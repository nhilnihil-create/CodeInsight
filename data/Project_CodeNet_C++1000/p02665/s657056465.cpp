#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i, j, k, n, now = 1, ans;
  scanf("%lld", &n);
  ll a[n + 1], b[n + 1];
  for(i = 0; i <= n; ++i) {
    scanf("%lld", &a[i]);
    now -= a[i];
    if(now < 0) {
      printf("-1");
      return 0;
    }
    b[i] = now;
    now <<= 1ll;
    if(now > 1e16) now = 1e16;
  }
  now = ans = a[n];
  for(i = n; i; --i) {
    now = now < b[i - 1] ? now : b[i - 1], now += a[i - 1];
    ans += now;
  }
  printf("%lld", ans);
  return 0;
}