#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i, j, k, n, na = 0, nb = 0, a;
  scanf("%lld", &n);
  for(i = 0; i < n; ++i) {
    scanf("%lld", &a);
    if(i & 1) na ^= a;
    else nb ^= a;
  }
  if(n & 1) na ^= nb, nb = 0;
  if(!na && !nb) printf("Yes");
  else printf("No");
  return 0;
}