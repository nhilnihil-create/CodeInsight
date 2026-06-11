#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

constexpr ll mod = 1e9+7;

ll mod_pow(ll a, ll n, ll mod){
    ll ret = 1;
    while(n > 0){
        if(n & 1LL) ret = (ret*(a % mod))%mod;
        a = ((a%mod)*(a%mod)) % mod;
        n = n >> 1;
    }
    return ret;
}

ll mod_inv(ll a, ll mod){
    return mod_pow(a, mod-2, mod);
}

ll mod_nck(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    if(k == 0 || k == n) return 1;
    ll ret = 1;
    rep(i, 1, k+1){
        ret *= (n-i+1);
        ret %= mod;
        ret *= mod_inv(i, mod);
        ret %= mod;
    }
    return ret;
}

int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    ll sum = mod_pow(2, n, mod) - 1;
    sum %= mod;
    sum -= mod_nck(n, a);
    sum %= mod;
    sum -= mod_nck(n, b);
    sum %= mod;
    if(sum < 0) sum += mod;
    cout << sum << endl;
    return 0;
}