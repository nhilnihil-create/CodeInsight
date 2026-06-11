#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
const ll mod = 1e9+7;

ll modpow(ll a, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n % 2) res = res * a % mod;
    a = a * a % mod;
    n /= 2;
  }
  return res;
}

ll modcomb(ll p, ll q) {
  ll bunshi = 1, bumbo = 1;
  for (ll i = p; i > p-q; i--) bunshi = bunshi * i % mod;
  rep(i,q) bumbo = bumbo * (i+1) % mod;
  
  return bunshi * modpow(bumbo, mod-2) % mod;
}

int main() {
  ll x, y;
  cin >> x >> y;
  
  if ((x+y)%3 != 0) cout << 0 << endl;
  else {
    ll n = (2*y-x)/3;
    ll m = (2*x-y)/3;
    if (n < 0 || m < 0) cout << 0 << endl;
    else cout << modcomb(n+m, min(n,m)) << endl;
  }
}