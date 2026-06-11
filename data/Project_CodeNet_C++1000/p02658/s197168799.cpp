#include <stdio.h>

int main() {
  int x;
  scanf("%d", &x);
  long long int a[x], maximum = 1e18;
  long long int prod = 1;
  long long int flag = 0; 
  long long int num = 0;
  
  for (int i = 0; i < x; i++) {
    scanf("%lld", &a[i]);
    flag = (a[i] > maximum) ? 1 : flag;
    prod *= a[i];
    (a[i]) ? maximum /= a[i] : num = 1;
  }

  (num) ? puts("0") : ((flag) ? puts("-1") : printf("%lld\n", prod));
  return 0;
}