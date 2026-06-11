#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define MOD 1000000007

ll modpow(ll x, ll n, ll mod){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

ll modinv(ll x, ll mod){
    return modpow(x, mod-2, mod);
}

int main(){
    ll n, a, b; cin >> n >> a >> b;
    ll ans;
    ans = (modpow(2, n, MOD) - 1) % MOD;
    ll bunshi = 1, bunvo = 1;
    for(int i = 0; i < a; i++){
        bunshi = bunshi * (n - i) % MOD;
        bunvo = bunvo * (i + 1) % MOD;
    }
    ans = (ans - bunshi * modinv(bunvo, MOD) % MOD + MOD) % MOD;
    bunshi = bunvo = 1;
    for(int i = 0; i < b; i++){
        bunshi = bunshi * (n - i) % MOD;
        bunvo = bunvo * (i + 1) % MOD;
    }
    ans = (ans - bunshi * modinv(bunvo, MOD) % MOD + MOD) % MOD;
    cout << ans << endl;
}