#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double EPS = 1e-10;


ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}


int main(void) {
  ll N;
  cin >> N;

  if (N == 1) {
    cout << 0 << endl;
    return 0;
  } else if (N == 2) {
    cout << 2 << endl;
    return 0;
  }

  const ll mod7 = 1000000000 + 7;
  ll ans = modpow(10, N, mod7);
  ans -= modpow(9, N, mod7);
  ans -= modpow(9, N, mod7);
  ans += modpow(8, N, mod7);

  ans %= mod7;
  ans = (ans+mod7) % mod7;
 
  cout << ans << endl;
  
  return 0;
}