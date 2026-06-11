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
    ll tmp=1;
    // 分子
    for(int i=n;i>=n-k+1;i--){
        tmp *= i % mod;
        tmp %= mod;
    }
    // 分母
    for(int i=k;i>0;i--){
        ll rev = modpow(i,mod-2,mod);
        tmp *= rev % mod;
        tmp %= mod;
    }
    // cout << "tmp: " << tmp << endl;
 
    return tmp;
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