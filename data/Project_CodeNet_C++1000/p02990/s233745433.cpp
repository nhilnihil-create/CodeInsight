#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll MOD = 1e9 + 7;
const int N = 2005;

vector<ll> mf(N, -1);
ll modfact(ll n) {
  if (mf[n] != -1) return mf[n];
  if (n == 0) return mf[0] = 1;
  return mf[n] = n * modfact(n-1) % MOD;
}

ll modinv(ll a) {
  ll b = MOD, u = 1, v = 0;
  while (b) {
    ll t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= MOD;
  if (u < 0) u += MOD;
  return u;
}

vector<ll> mif(N, -1);
ll modinvfact(ll n) {
  if (mif[n] != -1) return mif[n];
  if (n == 0) return mif[0] = 1;
  return mif[n] = modinv(n) * modinvfact(n-1) % MOD;
}

ll modcomb(ll n, ll k) {
  return modfact(n) * modinvfact(k) % MOD * modinvfact(n-k) % MOD;
}

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= k; ++i) {
    ll ans = 0;
    if (i == 1) {
      ans = n - k + 1;
      cout << ans << endl;
      continue;
    }
    for (int j = i-1; j <= n-k; ++j) {
      ans = (ans + modcomb(j-1, i-2) * (n-k-j+1)) % MOD;
    }
    ans = ans * modcomb(k-1, i-1) % MOD;
    cout << ans << endl;
  }
  return 0;
}