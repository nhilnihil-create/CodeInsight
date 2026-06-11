#include <stdio.h>

int main() {
  int k , x;
  scanf("%d %d", &k, &x);
  if(k * 500 >= x) puts("Yes");
  else puts("No");
  return 0;
}
