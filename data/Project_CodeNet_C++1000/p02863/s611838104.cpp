#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
const ll M = 1e9 + 7;

int main(void){
  int n, t;
  scanf("%d %d", &n, &t);
  vi as(n), bs(n);
  rep(i, n) scanf("%d %d", &as[i], &bs[i]);
  vector<vector<vi>> dp(2, vector<vi>(n + 1, vi(t, 0)));

  rep(i, n) rep(j, t){
    dp[0][i + 1][j] = dp[0][i][j];
    dp[1][i + 1][j] = dp[1][i][j];

    if (j - as[i] >= 0)
      dp[0][i + 1][j] = max(dp[0][i][j], dp[0][i][j - as[i]] + bs[i]);
    if (j - as[n - 1 - i] >= 0)
      dp[1][i + 1][j] = max(dp[1][i][j], dp[1][i][j - as[n - 1 - i]] + bs[n - 1 - i]);
    // cout << i << " " << j << " " << dp[0][i + 1][j] << endl;
  }

  int ans = 0;
  rep(i, n)
    rep(j, t)
      ans = max(ans, bs[i] + dp[0][i][j] + dp[1][n - 1 - i][t - 1 - j]);

  printf("%d\n", ans);

  return 0;
}
