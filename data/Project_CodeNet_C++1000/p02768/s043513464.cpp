#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repI(i, d, n) for (int i = (d); i < (n); ++i)
#define reps1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;
using P = pair<int, int>;
using Pl = pair<ll, ll>;
using M = map<int, int>;
ll const INF = 1ll<<61;
double pi = 3.141592653589793238;
ll const MOD = 1e9+7;

ll mod_pow(ll a, ll n, ll p) {
  if (n == 1) return a % p;
  if (n % 2 == 1) return (mod_pow(a, 1, p) * mod_pow(a, n-1, p)) % p;
  ll t = mod_pow(a, n / 2, p);
  return (t * t) % p;
}

ll mod_multi(ll a, ll b, ll p) {
  ll res = 1;
  rep(i, b) {
    res = res * a % p;
    a--;
  }
  return res % p;
}

ll mod_com(ll a, ll b, ll p) {
  b = min(b, a-b);
  ll res = mod_multi(a, b, p);
  ll tmp = mod_multi(b, b, p);
  tmp = mod_pow(tmp, MOD-2, MOD) % MOD;

  res = (res * tmp) % MOD;
  return res;
}

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  ll ans = 0;

  ans = mod_pow(2, n, MOD) - 1;
  ans -= mod_com(n, a, MOD);
  ans -= mod_com(n, b, MOD);
  ans %= MOD;
  while (ans < 0) ans += MOD;
  
  cout << ans <<endl;

  return 0;
}
