#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
using ll = long long;

int dp[1001][MAX];

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h, n;
  cin >> h >> n;

  int a[n], b[n];
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];

  for (int i = 0; i < 1001; ++i) {
    for (int j = 0; j < MAX; ++j) {
      dp[i][j] = 1000000000;
    }
  }
  dp[0][0] = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < MAX; ++j) {
      if (j - a[i] >= 0) dp[i+1][j] = min({dp[i+1][j], dp[i+1][j-a[i]] + b[i], dp[i][j-a[i]] + b[i]});
      dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
    }
  }

  int ans = 1000000000;
  for (int i = h; i < MAX; ++i) ans = min(ans, dp[n][i]);

  cout << ans << '\n';

  return (0);
}
