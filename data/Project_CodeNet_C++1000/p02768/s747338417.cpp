#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long double ld;
typedef long long ll;
const int MOD =  1000000007;
const int IINF = INT_MAX;
const ll INF = 1LL << 60;

// 繰り返し二乗法
ll mod_pow(ll x, ll a){
    if(a == 1) return x;
    // 指数aが奇数の時はx*x^(a-1)
    if(a % 2) return (x * mod_pow(x, a - 1)) % MOD;
    // 指数aが偶数の時はx^(a/2)
    ll t = mod_pow(x, a / 2);
    return (t * t) % MOD;
}

// フェルマーの小定理からxのMOD-2乗を計算
ll mod_inv(ll x){
    return mod_pow(x, MOD - 2);
}

// kまでの階乗計算
ll mod_perm(ll n, ll k){
    ll ret = 1;
    for(int i = 0; i < k; i++){
        ret = (ret * (n - i)) % MOD;
    }
    return ret;
}

// 二項係数(n = 1e9, k = 1e7まで対応可能))
ll mod_comb(ll n, ll k){
    ll a, b;
    // n - k + 1からnまでの積
    a = mod_perm(n, k);
    // k!
    b = mod_perm(k, k);
    return (a * mod_inv(b)) % MOD;
}


int main() {
    ll n, a, b; cin >> n >> a >> b;
    ll ans = (mod_pow(2, n) - 1 - mod_comb(n, a) - mod_comb(n, b)) % MOD;
    ans = (ans + MOD) % MOD;
    cout << ans << endl;
}
