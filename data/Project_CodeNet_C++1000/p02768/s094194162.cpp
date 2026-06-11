#include <bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// mod. m での a の逆元 a^{-1} を計算する
// a^n mod を計算する
ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

ll calc(ll n, ll k, ll mod){
    ll a=1, b=1;
    // 分子
    rep(i, k){
        a = (a* (n-i)) % mod;
        b = (b*(i+1))% mod;
    }
    // cout << "tmp: " << tmp << endl;

    return a*modpow(b, mod-2, mod)%mod;
}


int main(){
    // 前処理
    ll mod = 1e9+7;
    ll N, a, b; cin >> N >> a >> b;

    ll all = modpow(2, N, mod)-1;
    // cout << "all: " << all << endl;
    ll ans = all-calc(N, a, mod)-calc(N, b, mod);
    while (ans<0) ans+=mod;
    cout << ans << endl;

    return 0;
}