#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
 
const ll M = (long long) 1e9+7;
 
vector<ll> fac(2000001); 
vector<ll> ifac(2000001); 
 
 
ll mpow(ll x, ll n){ 
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % M;
        x = x*x % M;
        n = n >> 1;
    }
    return ans;
}
 
ll comb(ll a, ll b){ 
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0 || b<0)return 0;
    ll tmp = ifac[a-b]* ifac[b] % M;
    return (tmp * fac[a]) % M;
}
 
int main()
{
    fac[0] = 1;
    ifac[0] = 1;
    for(ll i = 0; i<2000000; i++){
        fac[i+1] = fac[i]*(i+1) % M; 
        ifac[i+1] = ifac[i]*mpow(i+1, M-2) % M; 
    }

    ll S;
    cin >> S;
 
    ll n = S/3ll;
    ll ans=0ll;

    for(int i=1; i<=n; i++){

        ll Srest = S - 3ll * i;

        ans += comb( Srest+i-1, i-1 )%M;
        ans %= M;

        //cout << "i, ans, Srest " << i << " " << ans << " " << Srest << endl;
    }

    cout << ans << endl;

    return 0;
}