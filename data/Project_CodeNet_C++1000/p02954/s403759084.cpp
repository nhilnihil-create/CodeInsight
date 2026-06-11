#include <bits/stdc++.h>
using namespace std;
using Int = long long;
template <typename T1, typename T2>
inline void chmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
inline void chmax(T1 &a, T2 b) {
  if (a < b) a = b;
}

int main() {
  string s;
  cin >> s;
  Int n = s.size();

  vector<Int> ls(n, -1);
  for (Int i = 0; i < n; i++) {
    if (s[i] == 'L') {
      if (s[i - 1] == 'R')
        ls[i] = 0;
      else
        ls[i] = ls[i - 1] + 1;
    }
  }

  vector<Int> rs(n, n);
  for (Int i = n - 1; i >= 0; i--) {
    if (s[i] == 'R') {
      if (s[i + 1] == 'L')
        rs[i] = 0;
      else
        rs[i] = rs[i + 1] + 1;
    }
  }

  vector<Int> ans(n, 0);
  for (Int i = 0; i < n; i++) {
    if (s[i] == 'L') {
      ans[i - ls[i] - (ls[i] & 1)]++;
    }
    if (s[i] == 'R') {
      ans[i + rs[i] + (rs[i] & 1)]++;
    }
  }

  for (Int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << ans[i];
  }
  cout << endl;
  return 0;
}
