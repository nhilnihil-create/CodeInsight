#include <stdio.h>
#include <string.h>
typedef long long ll;

int main(void) {
  ll i, j, k, ans = 0, now = 0, cnt = 0;
  char s[500010];
  scanf("%s", s);
  ll a[strlen(s) + 1];
  for(i = 0; s[i]; ++i) if(s[i] == '<') {
    if(!i || s[i - 1] == '>') a[i] = 0;
    a[i + 1] = a[i] + 1;
  }
  for(--i; i >= 0; --i) if(s[i] == '>') {
    if(!s[i + 1] || s[i + 1] == '<') a[i + 1] = 0;
    if(!i || s[i - 1] == '>' || a[i] < a[i + 1] + 1) a[i] = a[i + 1] + 1;
  }
  for(i = 0; s[i]; ++i) ans += a[i];
  ans += a[i];
  printf("%lld", ans);
  return 0;
}