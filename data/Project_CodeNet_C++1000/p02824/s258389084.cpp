#include <stdio.h>
#include <algorithm>
typedef long long ll;

int main(void) {
  ll i, j, k, n, m, v, p, ans, now;
  scanf("%lld%lld%lld%lld", &n, &m, &v, &p);
  ll a[n], sum[n];
  sum[0] = 0;
  ans = p;
  for(i = 0; i < n; ++i) scanf("%lld", &a[i]);
  std::sort(a, a + n);
  sum[0] = a[0];
  for(i = 1; i < n; ++i) sum[i] = sum[i - 1] + a[i];
  for(i = 0; i < n - p; ++i) {
    if(a[i] + m < a[n - p]) continue;
    if(v < p + i) ++ans;
    else {
      now = sum[n - p] - sum[i];
      if((a[i] + m) * (n - p - i) - now >= m * (v - p - i)) ++ans;
    }
  }
  printf("%lld", ans);
  return 0;
}