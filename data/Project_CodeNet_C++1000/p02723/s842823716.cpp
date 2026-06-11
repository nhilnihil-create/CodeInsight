#include <stdio.h>

int main() {
  char s[7];
  scanf("%s", s);

  if(s[2] == s[3] && s[4] == s[5]) puts("Yes");
  else puts("No");
}