#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  
  long long int array[n], max = 1e18, product = 1, mark = 0, zero = 0;
  for (int i = 0; i < n; i++) {
    scanf("%lld", &array[i]);
    mark = (array[i] > max) ? 1 : mark;
    product *= array[i];
    (array[i]) ? max /= array[i] : zero = 1;
  }

  (zero) ? puts("0") : ((mark) ? puts("-1") : printf("%lld\n", product));
  return 0;
}