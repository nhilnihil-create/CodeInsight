#include <stdio.h>
#define mod 1000000007
typedef long long ll;

ll rev(ll a) {
  ll ans = 1, now = mod - 2;
  while(now) {
    if(now & 1) ans *= a, ans %= mod;
    a *= a, a %= mod, now >>= 1;
  }
  return ans;
}

int main(void) {
  ll i, j, k, n, sum = 0, ans, a, b;
  scanf("%lld%lld", &n, &k);
  ll cnt[n], fact[k + 1];
  for(i = 0; i < n; ++i) cnt[i] = 0;
  fact[0] = 1;
  for(i = 1; i <= k; ++i) fact[i] = fact[i - 1] * i, fact[i] %= mod;
  for(i = 1; i < n; ++i) scanf("%lld%lld", &a, &b), cnt[--a]++, cnt[--b]++;
  if(cnt[0] >= k) {
    printf("0");
    return 0;
  }
  ans = fact[k] * rev(fact[k - cnt[0] - 1]);
  ans %= mod;
  for(i = 1; i < n; ++i) {
    if(cnt[i] >= k) {
      printf("0");
      return 0;
    }
    ans *= fact[k - 2];
    ans %= mod;
    ans *= rev(fact[k - cnt[i] - 1]);
    ans %= mod;
  }
  printf("%lld", ans);
  return 0;
}