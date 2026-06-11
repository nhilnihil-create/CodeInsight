#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  long long int arr[n], max = 1e18, res = 1, check = 0, zero = 0;
  
  int c;
  for (c = 0; c < n; c++) {
    scanf("%lld", &arr[c]);
    check = (arr[c] > max) ? 1 : check;
    res *= arr[c];
    (arr[c]) ? max /= arr[c] : zero = 1;
  }

  (zero) ? printf("0\n") : ((check) ? printf("-1\n") : printf("%lld\n", res));
  return 0;
}
