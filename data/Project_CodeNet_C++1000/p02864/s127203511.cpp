#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

const ll INF = 400000000000;

// dp[i][n]: もっとも右側の列がiで、これまでの列数がnのときの最小コスト
ll dp[3100][3100];

signed main() {
  rep(i,3100) rep(j,3100) dp[i][j] = INF;
  ll N, K;
  cin >> N >> K;
  vector<ll> h(N+1, 0);
  for (ll i=1; i<=N; i++)
    cin >> h[i];
  dp[0][0] = 0;
  for (ll i = 1; i<= N; i++) for (ll n = 1; n<=N; n++) {
    for (ll j = 0; j <= i-1; j++) {
      dp[i][n] = min(dp[i][n], dp[j][n-1] + max((ll)0, h[i]-h[j]));
    }
  }

  ll ans = INF;
  for (ll i=0; i<=N; i++) {
    ans = min(ans, dp[i][N-K]);
  }
  cout << ans << endl;
}
