#include <stdio.h>
#define mod 1000000007
typedef long long ll;

int main(void) {
  ll i, j, k, n, m;
  scanf("%lld%lld", &n, &m);
  ll dp[n + 1][m + 1], s[n], t[m];
  for(i = 0; i < n; ++i) scanf("%lld", &s[i]);
  for(i = 0; i < m; ++i) scanf("%lld", &t[i]);
  for(i = 0; i <= n; ++i) dp[i][0] = 1;
  for(i = 0; i <= m; ++i) dp[0][i] = 1;
  for(i = 0; i < n; ++i) for(j = 0; j < m; ++j) {
    dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j];
    if(s[i] != t[j]) dp[i + 1][j + 1] += mod - dp[i][j];
    dp[i + 1][j + 1] %= mod;
  }
  printf("%lld", dp[n][m]);
  return 0;
}