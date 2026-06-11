#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n); i > 0; i--)
#define print(n) cout << n << endl

ll modpow(ll m, ll n, ll mod){
    ll ans = 1;
    while(n){
        if(n & 1) ans = ans * m % mod;
        m = m * m % mod;
        n >>= 1;
    }
    return ans;
}

int main(){
    ll n;
    ll k;
    ll ans=0;
    const int mod = 1000000007;

    cin >> n >> k;
    int m;
    vector<ll> vec(k+1);
    rrep(i,k){
        m = k/i;
        vec.at(i) = modpow(m,n,mod);
        if(m>=2) for(int j=2;j<m+1;j++) vec.at(i) = (vec.at(i) - vec.at(i*j) + mod) % mod;
        ans = (ans + vec.at(i) * i) % mod;
    }
    cout << ans << endl;

    return 0;
}