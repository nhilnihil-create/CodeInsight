#include <iostream>
#include <map>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
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
    auto it = next[result % s.size()].find(t[i]);
    if (it == next[result % s.size()].end()) {
      result = -1;
      break;
    }
    result += it->second - result % s.size() + 1;
  }
  cout << result;
  return 0;
}