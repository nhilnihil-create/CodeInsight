#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
long long longpow(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a%MOD;
  if (b % 2 == 1) return (a  * longpow(a, b - 1)) % MOD;
  ll t = longpow(a, b / 2)%MOD;
  return (t * t) % MOD;
}
long long modpow(long long a, long long n) {
  long long res = 1;
  long long mod = n + 2;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}
long long inverse(long long x, long long modding) {
  return modpow(x, modding - 2);
}
ll comb(ll r, ll a) {
  ll R = r;
  REP(i, a - 1) {
    r--;
    R *= r;
    R %= MOD;
  }
  ll A = 1;
  for (int i = 1; i <= a; i++) {
    A *= i;
    A %= MOD;
  }
  return R * inverse(A, MOD) % MOD;
}


int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  ll ans = longpow(2,n) - 1;
  ans -= comb(n, a);
  ans -= comb(n, b);
  while (ans < 0) {
    ans += MOD;
  }
  cout << ans << endl;
}