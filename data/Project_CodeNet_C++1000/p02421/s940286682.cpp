#include <stdio.h>
#include <string.h>
#define rep(i, a) for(int i = 0; i < a; ++i)

int main(void) {
  char s[250], t[250];
  int n, i, j, a = 0, b = 0;
  scanf("%d", &n);
  rep(i, n) {
    scanf("%s %s", s, t);
    if(strcmp(s, t) > 0) a += 3;
    else if(!strcmp(s, t)) a++, b++;
    else b += 3;
  }
  printf("%d %d\n", a, b);
  return 0;
}
