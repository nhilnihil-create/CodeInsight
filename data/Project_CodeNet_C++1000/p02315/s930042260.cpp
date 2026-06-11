#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define shosu(n) setprecision(n)
#define INF 999999999
using namespace std;
int main() {
  int N, W;
  cin >> N >> W;
  int n[N], w[N], dp[N + 10][W + 10] = {0};
  rep(i, N) cin >> n[i] >> w[i];
  rep(i, N) rep(j, W + 1) dp[i][j] = -1;
  dp[0][0] = 0;
  rep(i, N) rep(j, W + 1) {
    if (dp[i][j] >= 0) {
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      if (w[i] + j <= W)
        dp[i + 1][j + w[i]] = max(dp[i + 1][j + w[i]], dp[i][j] + n[i]);
    }
  }
  int ans = 0;
  rep(j, W + 1) {
    ans = max(ans, dp[N][j]);
  }
  cout << ans << endl;
  return 0;
}