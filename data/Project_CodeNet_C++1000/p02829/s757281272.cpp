#include <stdio.h>

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  if(a == 1 && b == 2) puts("3");
  else if(a == 1 && b == 3) puts("2");
  else if(a == 2 && b == 3)puts("1");
  else if(a == 3 && b == 1) puts("2");
  else if(a == 3 && b == 2) puts("1");
  else if(a == 2 && b == 1) puts("3");
  return 0;
}