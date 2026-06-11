#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const ll M = 7ll + (long long) 1e9;
const int NMAX = 1 + (int) 2e5;

vector <ll> inv(NMAX);


ll mpow(ll x, ll n){ 
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % M;
        x = x*x % M;
        n = n >> 1;
    }
    return ans;
}
/*
ll mpow(ll x, ll n){ 
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % M;
        x = x*x % M;
        n = n >> 1;
    }
    return ans;
}*/

ll Comb_(ll n, ll k){
    ll tmp=1;
    for(ll i=1; i<=k; i++){
        tmp = tmp*(n+1-i)%M;
    }
    for(ll i=1; i<=k; i++){
        tmp = tmp*inv[i]%M;
    }

    return tmp;
}

/*
ll fac(ll x){
    ll fac0;
    fac0 = 1;
    for(ll i = 0; i<x; i++){
        fac0 = fac0*(i+1) % M;  
    }
    return fac0;
}

long long pow_mod(long long a, long long b, long long m) {
  long long res=1;
  for(;b;b>>=1, a=a*a%m) {
    if(b&1) res=res*a%m;
  }
  return res;
}

ll ifac(ll x){
    ll ifac0;
    ifac0 = pow_mod(fac(x), M-2, M);  
    //ifac0 = mpow(fac(x), M-2);

    return ifac0;
}
 
ll comb(ll a, ll b){ 
    if(a == 0 && b == 0)return 1;
    if(b == 0) return 1;
    if(a < b || a < 0 || b<0)return 0;

    ll ifac_ab, ifac_b, fac_a;

    ifac_ab = ifac(a-b);
    ifac_b = ifac(b);
    fac_a = fac(a);    

    ll tmp = ifac_ab* ifac_b % M;
    return tmp * fac_a % M;
}
*/
 
int main()
{
    ll N,a,b;
    cin >> N >> a >> b;
    ll nCa, nCb, ans;

    for(int i=1; i<=(int) max(a,b); i++){
        inv[i] = mpow((long long) i, M-2);
        //cout << "i inv[i] " << i << " " << inv[i] << endl;
    }


    nCa= Comb_(N, a);
    nCb= Comb_(N, b);
    //ans = fac(N-a);
    ll sum = mpow(2,N);
    ll sub = (1 + nCa + nCb)%M;
    if( sum >= sub ){
        ans = ( sum - sub ) % M;
    }else{
        ans = (sum + M - sub) % M;
    }
    //cout << "mpow(2,N), nCa, nCb " << mpow(2,N) << " " << nCa << " " << nCb << endl;
    cout << ans << endl;
 
    return 0;
}