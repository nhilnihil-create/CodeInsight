#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define loop(i, a, n) for(int i = (a); i < (n); i++)
using namespace std;
using ll = int64_t;

ll mod_pow(ll x, ll n, const ll mod){
    ll ans = 1;
    while(n){
        if(n & 1) ans = ans * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ans;
}

int main(){
    const ll mod = 1e9+7;
    int n, k; cin >> n >> k;

    ll d[k+1];
    loop(i, 1, k+1) d[i] = mod_pow(k/i, n, mod);
    for(int i = k; i > 0; i--){
        for(int j = 2*i; j < k+1; j += i){
            d[i] -= d[j];
            d[i] %= mod;
        }
    }
    ll ans = 0;
    loop(i, 1, k+1){
        ans += d[i]*i;
        ans %= mod;
    }
    cout << ans << endl;

    return 0;
}