#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  long long int array[n], max = 1e18;
  long long int prod = 1;
  long long int flag = 0;
  long long int zero = 0;
  
  for (int i = 0; i < n; i++) {
    scanf("%lld", &array[i]);
    flag = (array[i] > max) ? 1 : flag;
    prod *= array[i];
    (array[i]) ? max /= array[i] : zero = 1;
  }

  (zero) ? puts("0") : ((flag) ? puts("-1") : printf("%lld\n", prod));

  return 0;
}