#include <stdio.h>
typedef long long ll;

ll min(ll a, ll b) {
  return a > b ? b : a;
}

ll max(ll a, ll b) {
  return a > b ? a : b;
}

int main(void) {
  ll i, j, k, l, n, ans = 0, now;
  scanf("%lld%lld", &n, &k);
  ll h[n + 2], dp[n + 2][n + 1], d[n + 2][n + 1];
  h[0] = 0, h[n + 1] = 0;
  for(i = 1; i <= n; ++i) scanf("%lld", &h[i]);
  for(i = 0; i <= n; ++i) if(h[i + 1] > h[i]) ans += h[i + 1] - h[i];
  for(i = 0; i < n + 2; ++i) for(j = 0; j <= n; ++j) dp[i][j] = d[i][j] = 0;
  for(i = 2; i < n + 2; ++i) {
    for(j = i - 1; j; --j) {
      d[i][i - j] = d[i][i - j - 1];
      if(h[j] < h[i]) {
        if(h[j - 1] > h[j]) d[i][i - j] += min(h[j - 1], h[i]) - h[j];
      } else if(h[j] > h[j - 1]) d[i][i - j] += h[j] - max(h[j - 1], h[i]);
    }
  }
  for(i = 2; i < n + 2; ++i) {
    dp[i][0] = dp[i - 1][0];
    for(j = 1; j <= k; ++j) dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    for(j = 1; j < i; ++j) for(l = 0; l <= k - j; ++l) if(dp[i - j - 1][l] + d[i][j] > dp[i][l + j]) 
      dp[i][l + j] = dp[i - j - 1][l] + d[i][j];
  }
  printf("%lld", ans - dp[n + 1][k]);
  return 0;
}