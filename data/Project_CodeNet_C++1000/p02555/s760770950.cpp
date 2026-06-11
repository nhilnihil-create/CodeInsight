#include <iostream>
using namespace std;
using ll = long long;

const int MAX = 5100;
int mod = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++){
    fac[i] = fac[i - 1] * i % mod;
    inv[i] = mod - inv[mod%i] * (mod / i) % mod;
    finv[i] = finv[i - 1] * inv[i] % mod;
  }
}

ll com(int n, int k){
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

int main() {
  int n;
  cin >> n;
  COMinit();
  ll ans = 0;
  for (int i = 1; 3*i <= n; ++i) {
    ans += com(n-2*i-1, n-3*i);
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}