#include <stdio.h>
#include <string.h>

int main() {
  int a, b;
  char s[11], t[11], u[11];
  scanf("%s %s %d %d %s", s, t, &a, &b, u);

  if(strcmp(s, u) == 0) printf("%d %d\n", a - 1, b);
  else printf("%d %d\n", a, b - 1);
  return 0;
}
