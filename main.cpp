#include <algorithm>
#include <climits>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../utils/PrintUtils.hpp"
#include "../utils/VectorUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// https://leetcode.com/problems/check-if-it-is-a-straight-line/
// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() { // NOLINT
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  bool isLetter(char c) { return c >= 'a' && c <= 'z'; }
  string reformat(string &s) {
    // start with letter or digit
    int sz = s.length();
    if (s.empty() || sz == 1)
      return s;
    vector<bool> v(sz);
    int letters = 0;
    for (int i = 0; i < sz; i++) {
      if (isLetter(s[i])) {
        ++letters;
        v[i] = true;
      } else {
        v[i] = false;
      }
    }
    if (abs(sz - 2 * letters) > 1) {
      return "";
    }
    if (letters > sz - letters) {
      // must start with a letter
      int i = 0;
      while (!v[i]) {
        i++;
      }
      swap(s[0], s[i]);
      swap(v[0], v[i]);
    }
    if (letters < sz - letters) {
      // must start with a number
      int i = 0;
      while (v[i]) {
        i++;
      }
      swap(s[0], s[i]);
      swap(v[0], v[i]);
    }
    for (int i = 1; i < s.length(); i++) {
      if (v[i - 1] == v[i]) {
        // find one to swap;
        int index = i + 1;
        while (index < s.size() && (v[i - 1] == v[index])) {
          ++index;
        }
        if (index == s.size())
          return "";
        swap(s[i], s[index]);
        swap(v[i], v[index]);
      }
    }
    return s;
  }
};

void test1() {
  cout << boolalpha;
  vector<int> arr{1, 2, 3};
  string s = "covid2019";
  cout << "c2v0d1i9o ? " << Solution().reformat(s) << endl;
  s = "ab123";
  cout << "1a2b3 ? " << Solution().reformat(s) << endl;
}

void test2() {}

void test3() {}