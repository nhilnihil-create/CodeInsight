#include <bits/stdc++.h>

const int N = 1e5 + 10;
const int mod = 1e9 + 7;
typedef long long ll;

inline ll qpow(ll a, ll b) {
  ll res = 1;
  for (; b; b >>= 1, a = 1ll * a % mod * a % mod) {
    if (b & 1) {
      res = 1ll * res * a % mod;
    }
  }
  return res;  
}

int n, m, i, j, k;
ll dp[N];

int main() {
  scanf("%d %d", &n, &k);
  ll ans = 0;
  for (int i = k; i >= 1; i--) {
    dp[i] = qpow(k / i, n);
    for (int j = i * 2; j <= k; j += i) {
      dp[i] = (dp[i] - dp[j] + mod) % mod;
    }
    ans = (ans + 1ll * i % mod * dp[i] % mod) % mod;
  }
  printf("%lld\n", ans);
  return 0;  
} 
