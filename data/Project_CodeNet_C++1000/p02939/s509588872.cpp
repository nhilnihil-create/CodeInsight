#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i, j, k, ans = 0;
  char s[200010];
  scanf("%s", s);
  for(i = 0; s[i]; ++i) {
    if(s[i] == s[i + 1]) {
      if(s[i + 2]) ans += 2, i += 2;
      else ans += 1, i++;
    } else ans += 1;
  }
  printf("%lld", ans);
  return 0;
}