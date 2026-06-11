#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
vector<ll> fac, finv, inv;

ll combCalc(ll n, ll k){
    if(n<k) return 0;
    if(n<0 || k<0) return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}
ll comb(ll x, ll y){
    fac = finv = inv = vector<ll>(x+1);
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i=2; i<=x; i++){
        fac[i] = fac[i-1]*i%MOD;
        inv[i] = MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i] = finv[i-1]*inv[i]%MOD;
    }
    return combCalc(x, y);
}


int main(){
    ll x, y;    cin >> x >> y;
    ll ex=x/2, ox=x%2, ans=0;
    
    while(0<=ex){

        if(2*ex+ox==x && ex+2*ox==y){
            ans = comb(ex+ox, ox);
            break;
        }

        ex -= 1; ox += 2;
    }
    cout << ans << endl;
}