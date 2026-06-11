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
using Ml = map<ll, ll>;
ll const INF = 1ll<<61;
ll const MOD = 1e9 + 7;
double pi = 3.141592653589793238;

ll mod_pow(ll a, ll n, ll p) {
  if (n == 1) return a % p;
  if (n % 2 == 1) return (mod_pow(a, 1, p) * mod_pow(a, n-1, p)) % p;
  ll t = mod_pow(a, n / 2, p);
  return (t * t) % p;
}

int main() {
  ll n;
  cin >> n;

  ll ans = mod_pow(10, n, MOD) - 2 * mod_pow(9, n, MOD) + mod_pow(8, n, MOD);
  ans %= MOD;
  if (ans < 0) ans += MOD;
  cout << ans << endl;

  return 0;
}
