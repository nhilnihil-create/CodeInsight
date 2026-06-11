// 2020-08-17 21:25:24
#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
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
using P = pair<int, int>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

const int MX = 310;
const ll inf = 1e18;
ll dp[MX][MX];
void answer() {
  int n, k;
  cin >> n >> k;
  if(n == k) {
    cout << 0 << '\n';
    return;
  }
  vector<ll> h(n+1);
  rep(i, n) cin >> h[i+1];
  repc(i, n) repc(j, n) dp[i][j] = inf;
  dp[0][0] = 0;
  REPC(i, 1, n) rep(j, i) REPC(ki, 1, min(i, n-k)) {
    chmin(dp[i][ki], dp[j][ki-1] + max(0ll, h[i] - h[j]));
  }
  ll ans = inf;
  repc(i, n) chmin(ans, dp[i][n-k]);
  cout << ans << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}