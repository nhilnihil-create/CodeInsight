#include <stdio.h>

int main() {
  int a;
  scanf("%d", &a);
  long long int arr[a], max = 1e18, prod = 1, flag = 0, kosong = 0;
  
  for (int i = 0; i < a; i++) {
    scanf("%lld", &arr[i]);
    flag = (arr[i] > max) ? 1 : flag;
    prod *= arr[i];
    (arr[i]) ? max /= arr[i] : kosong = 1;
  }

  (kosong) ? puts("0") : ((flag) ? puts("-1") : printf("%lld\n", prod));
  return 0;
}