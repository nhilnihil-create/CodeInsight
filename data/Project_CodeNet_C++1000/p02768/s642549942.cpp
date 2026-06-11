#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1000000000;
const int MOD = MM + 7;
const int MAX = 510000;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}
const ll INF = 1LL << 60;
const double pi = acos(-1.0);

ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll COM(ll n, ll k){
    ll res = 1;
    Rep(i, n-k+1, n+1) res = res * i % MOD;
    res = res * finv[k] % MOD;
    return res;
}

ll binarypow(ll a, ll n, ll mod) {
  ll res = 1;
  while(n > 0) {
    if(n & 1) {
      res *= a;
      res %= mod;
    }
    a *= a;
    a %= mod;
    n >>= 1;
  }
  return res;
}

int main() {
    COMinit();
    ll n, a, b; cin >> n >> a >> b;
    ll ans = binarypow(2, n, MOD) - 1;
    if(ans < 0) ans += MOD;
    (ans -= COM(n, a)) %= MOD;
    if(ans < 0) ans += MOD;
    (ans -= COM(n, b)) %= MOD;
    if(ans < 0) ans += MOD;
    cout << ans << endl;
}