#include <stdio.h>
typedef long long ll;

int main(void) {
  ll h1, m1, h2, m2, k, t;
  scanf("%lld%lld%lld%lld%lld", &h1, &m1, &h2, &m2, &k);
  t = (h2 - h1) * 60 + m2 - m1;
  printf("%lld", t - k);
  return 0;
}