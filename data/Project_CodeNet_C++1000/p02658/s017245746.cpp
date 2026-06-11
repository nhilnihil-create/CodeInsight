#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  long long int ary[n], max = 1e18, prod = 1, fjg = 0, nol = 0;
  
  for (int i = 0; i < n; i++) {
    scanf("%lld", &ary[i]);
    fjg = (ary[i] > max) ? 1 : fjg;
    prod *= ary[i];
    (ary[i]) ? max /= ary[i] : nol = 1;
  }

  (nol) ? puts("0") : ((fjg) ? puts("-1") : printf("%lld\n", prod));
  return 0;
}