// 2020-07-24 01:34:17
#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = long long;
using ld = long double;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

void answer() {
  int n;
  cin >> n;
  vector<vector<int> > a(n, vector<int>(n-1, -1));
  rep(i, n) {
    rep(j, n-1) {
      cin >> a[i][j];
      a[i][j]--;
    }
  }
  ll ans = 0;
  vector<int> c(n, 0);
  while(1) {
    ans++;
    vector<int> m(n, 0);
    bool matched = false;
    rep(i, n) {
      if(m[i] || c[i] == n-1) continue;
      int b = a[i][c[i]];
      if(m[b] || c[b] == n-1) continue;
      if(a[b][c[b]] == i) {
        matched = true;
        m[i] = m[b] = true;
        c[i]++;
        c[b]++;
      }
    }
    if(!matched) {
      cout << -1 << '\n';
      return;
    }
    bool done = true;
    rep(i, n) {
      done &= (c[i] == n-1);
    }
    if(done) break;
  }
  cout << ans << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}