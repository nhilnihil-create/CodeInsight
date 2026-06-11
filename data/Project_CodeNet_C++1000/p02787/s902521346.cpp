#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using int64 = int64_t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, n;
  cin >> h >> n;
  int mx = h + 10010;
  const int INF = (int)1e8;
  vector<vector<int>> dp(n + 1, vector<int>(mx, INF));
  dp[0][0] = 0;
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    rep(j, mx) {
      if (j - a >= 0) {
        dp[i + 1][j] = min(dp[i][j], dp[i + 1][j - a] + b);
      } else {
        dp[i + 1][j] = dp[i][j];
      }
    }
  }
  int ans = INF;
  for (int i = h; i < mx; i++) {
    ans = min(ans, dp[n][i]);
  }
  cout << ans;
  return 0;
}