#include <stdio.h>

int main() {
  int Z;
  scanf("%d", &Z);
  long long int arr[Z], max = 1e18, prods = 1, flags = 0, zeroo = 0;
  
  for (int i = 0; i < Z; i++) {

    scanf("%lld", &arr[i]);
    flags = (arr[i] > max) ? 1 : flags;
    prods *= arr[i];
    (arr[i]) ? max /= arr[i] : zeroo = 1;

  }

  (zeroo) ? puts("0") : ((flags) ? puts("-1") : printf("%lld\n", prods));
  return 0;
}