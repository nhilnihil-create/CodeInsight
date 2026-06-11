#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i, n, ans = 0;
  scanf("%lld", &n);
  ll p[n];
  for(i = 0; i < n; ++i) scanf("%lld", &p[i]);
  for(i = 1; i < n - 1; ++i) 
    if((p[i - 1] > p[i] && p[i] > p[i + 1]) || (p[i - 1] < p[i] && p[i] < p[i + 1])) ++ ans;
  printf("%lld", ans);
  return 0;
}