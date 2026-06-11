#include <stdio.h>
#include <algorithm>
#define mod 1000000007
typedef long long ll;

ll  mul(ll a, ll b) {
  a *= b, a %= mod;
  return a;
}

ll rev(ll a) {
  ll now = mod - 2, ans = 1;
  while(now) {
    if(now & 1) ans = mul(ans, a);
    a = mul(a, a), now >>= 1;
  }
  return ans;
}

int main(void) {
  ll i, j, k, n, ans;
  scanf("%lld%lld", &n, &k);
  ll fact[n + 1];
  fact[0] = 1;
  for(i = 1; i <= n; ++i) fact[i] = mul(fact[i - 1], i);
  for(i = 1; i <= k; ++i) {
    if(n - k - i + 1 < 0) {
      printf("0\n");
      continue;
    }
    ans = mul(fact[n - k + 1], mul(rev(fact[i]), rev(fact[n - k - i + 1])));
    ans = mul(ans, fact[k - 1]);
    ans = mul(ans, mul(rev(fact[k - i]), rev(fact[i - 1])));
    printf("%lld\n", ans);
  }
  return 0;
}