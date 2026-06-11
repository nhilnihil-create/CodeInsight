#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rloop(i, n, a) for(int i = (n); i >= (a); i--)
#define loop(i, a, n) for(int i = (a); i < (n); i++)
using namespace std;
using ll = int64_t;

ll mod_pow(ll x, ll n, const ll mod){
    ll ans = 1;
    while(n){
        if(n & 1) ans = ans*x%mod;
        x = x*x%mod;
        n >>= 1;
    }
    return ans;
}

int main(){
    const ll mod = 1e9+7;
    ll n; int a, b; cin >> n >> a >> b;

    ll ans = mod_pow(2, n, mod) - 1;

    ll bunbo = 1, bunsi = 1;
    loop(i, 1, b+1){
        bunsi = (bunsi%mod) * ((n - i + 1)%mod) % mod;
        bunbo = (bunbo%mod) * (i%mod) % mod;
        if(i == a || i == b){
            ll tmp = mod_pow(bunbo, mod-2, mod);
            ans = (ans - (bunsi*tmp)%mod + mod )%mod;
        }
    }

    cout << ans%mod << endl;

    return 0;
}