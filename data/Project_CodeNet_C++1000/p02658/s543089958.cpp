#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  long long int arr[n], max = 1e18, x = 1, y = 0, zero = 0;
  
  for (int i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
    y = (arr[i] > max) ? 1 : y;
    x *= arr[i];
    (arr[i]) ? max /= arr[i] : zero = 1;
  }

  (zero) ? puts("0") : ((y) ? puts("-1") : printf("%lld\n", x));
  return 0;
}