#include <stdio.h>
#include <utility>
#include <algorithm>
typedef long long ll;

int main(void) {
  ll i, j, n, t, ans = 0;
  scanf("%lld%lld", &n, &t);
  ll dp[t + 3000];
  std::pair<ll, ll> p[n];
  for(i = 0; i < t + 3000; ++i) dp[i] = 0;
  for(i = 0; i < n; ++i) scanf("%lld%lld", &p[i].first, &p[i].second);
  std::sort(p, p + n);
  for(j = 0; j < n; ++j) {
    for(i = t - 1; i >= 0; --i) if(dp[i + p[j].first] < dp[i] + p[j].second) dp[i + p[j].first] = dp[i] + p[j].second;
  }
  for(i = 0; i < t + 3000; ++i) if(dp[i] > ans) ans = dp[i];
  printf("%lld", ans);
  return 0;
}