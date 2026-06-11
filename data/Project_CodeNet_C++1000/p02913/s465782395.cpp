#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i, j, k, n, ans = 0, h;
  scanf("%lld", &n);
  char s[n + 10];
  scanf("%s", s);
  for(i = 0; i < n; ++i) {
    ll t[n + 1];
    t[i] = -1, t[i + 1] = 0;
    for(j = i + 2; j < n; ++j) {
      if(s[i + t[j - 1]] == s[j - 1]) t[j] = t[j - 1] + 1;
      else t[j] = 0;
    }
    h = i + 1;
    for(j = i + 1; j < n; ++j) {
      while((h != j + 1 && s[j - h + i] != s[j]) || i + j >= 2 * h) 
        h = j - t[j - h + i];
      if(j - h + 1 > ans) ans = j - h + 1;
    }
  }
  printf("%lld", ans);
  return 0;
}