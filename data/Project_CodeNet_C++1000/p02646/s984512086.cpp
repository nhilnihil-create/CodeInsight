#include <stdio.h>
typedef long long ll;

int main(void) {
  ll a, b, v, w, t, d;
  scanf("%lld%lld%lld%lld%lld", &a, &v, &b, &w, &t);
  d = a > b ? a - b : b - a;
  printf("%s", d > (v - w) * t ? "NO" : "YES");
  return 0;
}