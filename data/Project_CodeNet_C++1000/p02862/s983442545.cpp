#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9+7;
const int N = 2e6+23;

int f[N];

int binpow(long long b, long long e) {
  if (!e) return 1;
  if (e&1) return b*binpow(b, e-1)%mod;
  return binpow(b*b%mod, e/2);
}
int C(int n, int k) {
  if(n - k < 0){
    cout << 0;
    exit(0);
  }
  return 1LL * f[n] * binpow(f[k], mod-2) % mod * binpow(f[n-k], mod-2) % mod;
}

int main() {

  ll x, y;
  cin >> x >> y;
  f[0] = 1;
  for (int i = 1; i <= 1000001; ++i) {
    f[i] = 1LL * f[i-1] * i % mod;
  }
  if(2 * x - y < 0) cout << "0";
  else if((x + y) % 3 != 0)cout << "0";
  else cout << C((x + y) / 3, (2 * x - y ) / 3);

  return 0;
}
