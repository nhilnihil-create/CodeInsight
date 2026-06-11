#include <stdio.h>
typedef long long ll;

ll min(ll a, ll b) {
  return a < b ? a : b;
}

int main(void) {
  ll i, j, k, n, a, b;
  scanf("%lld%lld%lld", &n, &a, &b);
  if((a + b) & 1) printf("%lld", min(a + b - 1, 2 * n - a - b + 1) >> 1);
  else printf("%lld", (b - a) >> 1);
  return 0;
}