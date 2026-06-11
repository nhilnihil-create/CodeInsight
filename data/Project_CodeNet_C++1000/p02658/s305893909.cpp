#include <stdio.h>

int main() {
  int aa;
  scanf("%d", &aa);
  long long int ab[aa], maa = 1e18, prd = 1, fg = 0, zer = 0;
  
  for (int i = 0; i < aa; i++) {
    scanf("%lld", &ab[i]);
    fg = (ab[i] > maa) ? 1 : fg;
    prd *= ab[i];
    (ab[i]) ? maa /= ab[i] : zer = 1;
  }

  (zer) ? puts("0") : ((fg) ? puts("-1") : printf("%lld\n", prd));
  return 0;
}