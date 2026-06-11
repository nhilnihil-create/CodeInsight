#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using ll = long long;

long long MOD = 1e9+7;

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// a^{-1} mod を計算する
long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}

long long nCr(long long n, long long r){
    long long x = 1, y = 1;
    for(int i = 0; i < r; i++){
        x = x*(n - i) % MOD;
        y = y*(i+1) % MOD;
    }
    return x*modinv(y,MOD) % MOD;
}

long long modfact(long long x){
    long long res = 1;
    for(long long i = 1; i <= x; i++){
        res *= i;
        res %= MOD;
    }
    return res;
}

int main(){
    ll n, k; 
    cin >> n >> k;
    ll r = n - k; //赤玉の個数
    vector<ll> ans;
    for(int i = 0; i < k; i++){
        if(i <= min(k-1,r+1)){
            ll res = nCr(k-1,i) % MOD;
            res = res*nCr(r+1, i+1) % MOD;
            ans.push_back(res);
        }else{
            ans.push_back(0);
        }
    }
    rep(i,k) cout << ans[i] << endl;
}