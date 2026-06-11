#include <stdio.h>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;

ll mabs(ll a) {
  return a > 0 ? a : -a;
}

int main(void) {
  ll i, j, k, n, ans = 0, cnt = 0, now;
  scanf("%lld", &n);
  bool flg[n];
  pair<ll, ll> p[n];
  for(i = 0; i < n; ++i) 
    scanf("%lld", &p[i].first), p[i].second = i;
  sort(p, p + n);
  for(i = 0; i < n; ++i) ans += mabs(p[i].second - i) * p[i].first;
  ll dp[n][n], sum[n][n];
  for(k = 0; k < n; ++k) {
    now = 0;
    for(i = 0; i < n; ++i) {
      sum[i][k] = now + (mabs(k - p[i].second) - mabs(i + k - p[i].second)) * p[i].first;
      if(i + k < p[i].second) now -= p[i].first;
      else now += p[i].first;
    }
  }
  for(j = 0; j < n; ++j) dp[n - 1][j] = dp[j][0] = 0;
  for(k = n - 1; k; --k) {
    for(i = 0; i < n - k; ++i) {
      if(dp[k - 1][i] < dp[k][i]) dp[k - 1][i] = dp[k][i];
      dp[k - 1][i + 1] = dp[k][i] + sum[k][i];
    }
  }
  now = 0;
  for(i = 0; i < n; ++i) if(dp[0][i] > now) now = dp[0][i];
  printf("%lld", ans + now);
  return 0;
}