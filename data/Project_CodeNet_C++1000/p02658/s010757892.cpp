#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  long long int arr[n], maks = 1e18, product = 1, flag = 0, zero = 0;
  
  for (int i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
    flag = (arr[i] > maks) ? 1 : flag;
    product *= arr[i];
    (arr[i]) ? maks /= arr[i] : zero = 1;
  }

  (zero) ? puts("0") : ((flag) ? puts("-1") : printf("%lld\n", product));
  return 0;
}
