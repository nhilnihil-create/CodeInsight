#include <stdio.h>
#include <set>
typedef long long ll;

int main(void) {
  ll i, j, k, ans = 0, tmp = 0;
  char s[110], t[110];
  bool flg = false;
  scanf("%s%lld", s, &k);
  for(i = 1; s[i]; ++i) if(s[i] != s[i - 1]) flg = true;
  if(flg) {
    for(i = 0; s[i]; ++i) {
      t[i] = s[i];
      if(i && t[i] == t[i - 1]) t[i] = '?', ++ans;
    }
    if(s[0] == t[i - 1]) s[0] = '?', ++tmp;
    for(i = 1; s[i]; ++i) if(s[i] == s[i - 1]) s[i] = '?', ++tmp;
    printf("%lld", ans + tmp * (k - 1));
  } else printf("%lld", i * k / 2);
  return 0;
}