#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i;
  char s[200010];
  scanf("%s", s);
  for(i = 0; s[i]; ++i) printf("%c", s[i] == '?' ? 'D' : s[i]);
  return 0;
}