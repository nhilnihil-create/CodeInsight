#include <iostream>
#include <set>
#include <map>
using namespace std;

bool check(const string& s, const string& t) {
  set<char> chars(begin(s), end(s));
  for (char c : t) {
    if (chars.count(c) == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  string s, t;
  cin >> s >> t;
  if (check(s, t)) {
    map<char, int> index, next[s.size()];
    for (int i = s.size() - 1; i >= 0; --i) {
      index[s[i]] = s.size() + i;
    }
    for (int i = s.size() - 1; i >= 0; --i) {
      index[s[i]] = i;
      next[i] = index;
    }
    int64_t result = 0;
    for (int64_t i = 0; i < t.size(); ++i) {
      result += next[result % s.size()][t[i]] - result % s.size() + 1;
    }
    cout << result;
  } else {
    cout << -1;
  }
  return 0;
}