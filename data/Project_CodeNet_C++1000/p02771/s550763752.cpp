#include <stdio.h>

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  if ( (a == b && b != c && a != c) || (a != b && b != c && a == c) || (a != b && b == c && a != c) ) puts("Yes");
  else puts("No");
  return 0;
}
