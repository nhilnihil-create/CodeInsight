#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1000000007;
vector<ll> fac(1000005);
vector<ll> ifac(1000005);
ll modpow(ll x, ll n){
    ll ans = 1;
    while(n != 0){
        if(n & 1)
            ans = ans * x % mod;
        x = x * x % mod;
        n = n >> 1;
    }
    return ans;
}
ll comb(ll a, ll b){
    if(a == 0 && b == 0)
        return 1;
    if(a < b || a < 0)
        return 0;
    ll tmp = ifac[a - b] * ifac[b] % mod;
    return tmp * fac[a] % mod;
}

int main(){
    ll x, y;
    cin >> x >> y;
    ll ans = 0;
    if((x + y) % 3 != 0 || 2 * x < y || 2 * y < x){
        cout << "0" << endl;
        return 0;
    }
    ll n, m;
    n = (2 * y - x) / 3;
    m = (2 * x - y) / 3;
    
    fac[0] = 1;
    ifac[0] = 1;
    for(ll i = 0; i < max(x, y); i++){
        fac[i + 1] = fac[i] * (i + 1) % mod;
        ifac[i + 1] = ifac[i] * modpow(i + 1, mod - 2) % mod;
    }
    cout << comb(n + m, n) << endl;
    return 0;
}