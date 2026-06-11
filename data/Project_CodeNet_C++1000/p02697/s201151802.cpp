#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i, m, n;
  scanf("%lld%lld", &n, &m);
  n = m / 2;
  for(i = 1; i <= n; ++i) printf("%lld %lld\n", i, m + 1 - i);
  n = (m + 1) / 2;
  for(i = 1; i <= n; ++i) printf("%lld %lld\n", i + m, 2 * m + 2 - i);
  return 0;
}