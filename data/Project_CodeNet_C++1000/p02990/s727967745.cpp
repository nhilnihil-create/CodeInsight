#include <bits/stdc++.h>
#define reg register
#define int long long
using namespace std;
const int MAXN = 5010;
const int mod = 1e9 + 7;
int n, k, fac[MAXN], inv[MAXN];
int getc(int n, int m) {
  if(m > n) return 0;
  return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}
void work() {
  fac[0] = inv[0] = fac[1] = inv[1] = 1;
  for(reg int i = 2; i <= 2000; ++i) fac[i] = 1ll * fac[i - 1] * i % mod, inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
  for(reg int i = 2; i <= 2000; ++i) inv[i] = 1ll * inv[i - 1] * inv[i] % mod;
  scanf("%lld%lld", &n, &k);
  for(reg int i = 1; i <= k; ++i) printf("%lld\n", getc(k - 1, i - 1) * getc(n - k + 1, i) % mod); 
}
signed main() {
  int _ = 1;
  // scanf("%d", &_);
  while(_--) work();
  return 0;
}
