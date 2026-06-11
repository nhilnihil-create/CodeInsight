#include <stdio.h>
int main() {
  int n;
  scanf("%d", &n);
  long long int arr[n], maximum = 1e18, prod = 1, flags = 0, zero = 0;
  
  for (int i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
    flags = arr[i] > maximum ? 1 : flags;
    prod *= arr[i];
    arr[i] ? maximum/= arr[i] : zero = 1;
  }

  (zero) ? puts("0") : ((flags) ? puts("-1") : printf("%lld\n", prod));
  return 0;
}