#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s, t;
  cin >> s >> t;
  int lenS = sz(s);
  int lenT = sz(t);
  vector<vector<int>> alpha(26);
  rep(i, lenS) {
    int c = s[i] - 'a';
    alpha[c].push_back(i);
  }
  rep(i, lenS) { // 2周目
    int c = s[i] - 'a';
    alpha[c].push_back(i+lenS);
  }
  ll ans = 0;
  int cur = 0;
  for (char c : t) {
    c = c - 'a';
    if (sz(alpha[c]) == 0) {
      puts("-1"); return 0;
    }
    cur = *lower_bound(alpha[c].begin(), alpha[c].end(), cur) + 1;
    if (cur >= lenS) {
      cur -= lenS;
      ans += lenS;
    }
  }
  ans += cur;
  cout << ans << '\n';
  return 0;
}