#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(pos,mp) for(ll pos=mp.begin();pos!=mp.end();pos -++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

const ll MAX = 1e6+7;
ll fac[MAX], finv[MAX], inv[MAX];
//初期化
void COMinit() {
    fac[0]  = fac[1]  = 1;
    finv[0] = finv[1] = 1;
    inv[1]  = 1;

    for(int i = 2; i < MAX; ++i){
        fac[i]  = fac[i - 1] * i % MOD;
        inv[i]  = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
//nCk
ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;

    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

//MODでべき乗が計算できる
ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(){
    ll n;
    cin >> n;

    // except mat that not contain 1 and 9
    ll ans = modpow(10, n, MOD);

    ll exp1and9 = modpow(8, n, MOD);
    ll exp1or9 = modpow(9, n, MOD) - exp1and9; 

    ans -= exp1and9 + 2 * exp1or9;
    ans += 10*MOD;
    ans %= MOD;

    cout << ans << endl;
}