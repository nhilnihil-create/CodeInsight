// 2020-08-17 20:03:15
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
ll dp[MX][MX][MX];
void answer() {
  int n, K;
  cin >> n >> K;
  vector<ll> h(n+1, 0);
  REPC(i, 1, n) cin >> h[i];
  repc(i, n) repc(j, n) repc(k, K) dp[i][j][k] = inf;
  dp[0][0][0] = 0;
  REPC(i, 1, n) {
    rep(j, i) {
      repc(k, K) {
        chmin(dp[i][i][k], dp[i-1][j][k] + max(h[i] - h[j], 0ll));
        if(k > 0) chmin(dp[i][j][k], dp[i-1][j][k-1]);
      }
    }
  }
  ll ans = inf;
  repc(j, n) repc(k, K) chmin(ans, dp[n][j][k]);
  cout << ans << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}