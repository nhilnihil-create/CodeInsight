#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<long long> h(n + 2);
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  vector<vector<long long>> dp(n + 2, vector<long long>(n + 3, 1LL << 55));
  dp[0][1] = 0;
  for (int i = 1; i <= n + 1; i++) for (int j = 1; j <= n + 2; j++) {
    for (int l = 0; l < i; l++) dp[i][j] = min(dp[i][j], dp[l][j - 1] + max(0LL, h[i] - h[l]));
  }
  long long ans = 1LL << 60;
  for (int i = n - k + 2; i <= n + 2; i++) {
    ans = min(ans, dp[n + 1][i]);
    //cerr << i << " " << dp[n + 1][i] << endl;
  }
  cout << ans << '\n';
  return 0;
}