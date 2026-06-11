#include <stdio.h>

int main() {
  int a, b;
  double c, d, f;
  scanf("%d%d",&a ,&b);
  c = a; d = b;

  printf("%d %d %f\n", a / b, a % b, c / d);
return 0;
}