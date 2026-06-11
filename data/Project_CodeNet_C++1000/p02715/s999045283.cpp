#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD =1e9+7;

ll modpow(ll a, ll n, ll mod = MOD) {
    ll rtn = 1;
    while (n > 0) {
        if (n & 1) rtn = rtn * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return rtn;
}


int main(){
    
    int N,K;
    cin >> N >> K;
    
    vector<ll> dd(K+1);
    vector<ll> d(K+1);
    ll ans=0;
    
    for(int i=K; i>0; i--){
        
        d.at(i) = modpow(K/i,N,MOD);
        
        for(int j=2*i; j<=K; j+=i){
            d.at(i) += (MOD - d.at(j))%MOD;//
        }
        
        ans += (i*d.at(i))%MOD;
        ans %= MOD;
        
    }
    
    cout << ans << endl;
    
    return 0;
}