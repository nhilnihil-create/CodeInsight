#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll Mod = 1000000007;

ll modPow(ll a, ll n, ll p) {
  if (n == 1) return a % p;
  if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
  ll t = modPow(a, n / 2, p);
  return (t * t) % p;
}

ll Fact(ll n,ll p) {
  if (n < 2) {
    return 1;
  }
  ll res = 1;
  for (ll i = n; i >= 1; i--) {
    res *= i;
    res %= p;
  }
  return res;
}

ll modinv(ll a,ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main() {
  ll n,a,b;
  cin >> n >> a >> b;
  ll aa = modinv(Fact(a,Mod),Mod);
  ll ba = modinv(Fact(b,Mod),Mod);
  ll as = 1;
  ll bs = 1;
  for (ll i = n-a+1; i <= n; i++) {
    as *= i;
    as %= Mod;
  }
  for (ll i = n-b+1; i <= n; i++) {
    bs *= i;
    bs %= Mod;
  }
  ll s = ((aa * as) % Mod) + ((ba * bs) % Mod);
  ll ans = (modPow(2,n,Mod) - 1 - s) % Mod;
  if (ans < 0) {
    ans += Mod;
  }
  cout << ans << endl;
  return 0;
}