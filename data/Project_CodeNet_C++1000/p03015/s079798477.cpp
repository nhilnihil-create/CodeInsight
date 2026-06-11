#include <stdio.h>
#include <string.h>
#define mod 1000000007
typedef long long ll;

int main(void) {
  ll i, j, k, n, ans, cnt = 1;
  char s[100010];
  scanf("%s", s);
  n = strlen(s);
  ll p3[n + 1], p2[n + 1];
  p3[0] = p2[0] = 1;
  for(i = 0; i < n; ++i) p3[i + 1] = (p3[i] * 3) % mod, p2[i + 1] = (p2[i] * 2) % mod;
  ans = p3[n - 1];
  for(i = 1; i < n; ++i) if(s[i] == '1') {
    ans += p3[n - i - 1] * p2[cnt];
    ans %= mod;
    cnt++;
  }
  ans += p2[cnt];
  ans %= mod;
  printf("%lld", ans);
  return 0;
}