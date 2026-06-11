// 2020-07-18 12:24:56
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
  vector<ll> a(n), ans(n);
  rep(i, n) cin >> a[i];
  ll b = 2 * a[n-1];
  REPCM(i, n-2, 0) b = 2 * a[i] - b;
  ans[0] = b / 2;
  REP(i, 1, n) ans[i] = 2 * a[i-1] - ans[i-1];
  rep(i, n) {
    if(i) cout << ' ';
    cout << ans[i];
  }
  cout << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}