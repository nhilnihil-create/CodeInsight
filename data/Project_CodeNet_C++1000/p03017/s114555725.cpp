#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i, j, k, n, a, b, c, d;
  scanf("%lld%lld%lld%lld%lld", &n, &a, &b, &c, &d);
  char s[n + 10];
  scanf("%s", s);
  for(i = a; i < c; ++i) if(s[i] + s[i - 1] == 'F') {
    printf("No");
    return 0;
  }
  for(i = b; i < d; ++i) if(s[i] + s[i - 1] == 'F') {
    printf("No");
    return 0;
  }
  if(c > d) {
    for(i = b - 1; i < d; ++i) if(s[i - 1] + s[i] == '\\' && s[i + 1] == '.') {
      printf("Yes");
      return 0;
    }
    printf("No");
    return 0;
  }
  printf("Yes");
  return 0;
}