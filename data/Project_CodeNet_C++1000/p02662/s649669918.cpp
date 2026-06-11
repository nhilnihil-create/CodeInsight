#include <stdio.h>
#define mod 998244353
typedef long long ll;

ll mul(ll a, ll b) {
  return a * b % mod;
}

ll pow(ll a, ll b) {
  ll ans = 1;
  while(b) {
    if(b & 1) ans = mul(ans, a);
    a = mul(a, a), b >>= 1;
  }
  return ans;
}

int main(void) {
  ll i, j, n, s, a, m = (mod + 1) / 2;
  scanf("%lld%lld", &n, &s);
  ll dp[s + 1];
  for(i = 0; i <= s; ++i) dp[i] = 0;
  dp[0] = pow(2, n);
  for(i = 0; i < n; ++i) {
    scanf("%lld", &a);
    for(j = s - a; j >= 0; --j) dp[j + a] += mul(dp[j], m), dp[j + a] %= mod;
  }
  printf("%lld", dp[s]);
  return 0;
}