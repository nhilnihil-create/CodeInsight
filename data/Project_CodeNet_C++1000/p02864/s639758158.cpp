#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n, K;
  cin >> n >> K;
  
  vector<ll> h(n);
  for (int i = 0; i < n; i++) cin >> h.at(i);
  
  vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n + 1, vector<ll>(n + 1, 1e18)));
  // dp[i][j][k]: i番目まで見て, 累計j個潰して, 連続k個潰しているときの最小操作回数
  dp[0][0][0] = h.at(0);
  dp[0][1][1] = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j <= i + 1; j++) {
      for (int k = 0; k <= i + 1; k++) {
        if (k == 0) {
          if (h.at(i) < h.at(i + 1)) {
            dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][k] + h.at(i + 1) - h.at(i));
            dp[i + 1][j + 1][k + 1] = min(dp[i + 1][j + 1][k + 1], dp[i][j][k]);
          }
          else {
            dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][k]);
            dp[i + 1][j + 1][k + 1] = min(dp[i + 1][j + 1][k + 1], dp[i][j][k]);
          }
        }
        else {
          int last = 0;
          if (i - k + 1 > 0) last = h.at(i - k);
          if (last < h.at(i + 1)) {
            dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][k] + h.at(i + 1) - last);
            dp[i + 1][j + 1][k + 1] = min(dp[i + 1][j + 1][k + 1], dp[i][j][k]);
          }
          else {
            dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][k]);
            dp[i + 1][j + 1][k + 1] = min(dp[i + 1][j + 1][k + 1], dp[i][j][k]);
          }
        }
      }
    }
  }
  
  ll ans = 1e18;
  for (int j = 0; j <= K; j++) {
    for (int k = 0; k <= K; k++) {
      ans = min(ans, dp[n - 1][j][k]);
    }
  }
  
  cout << ans << '\n';
}