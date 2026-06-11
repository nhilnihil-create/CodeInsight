#include<iostream>
#include<vector>
using namespace std;
#define ll long long
const ll MOD=1e9+7;
const int MAX=2e5+1;

ll modpow(ll x,ll n){
    ll res=1;
    while(n>0){
        if(n&1) res=res*x%MOD;
        x=x*x%MOD;
        n>>=1;
    }
    return res;
}

int main(){
    ll n,a,b;
    cin>>n>>a>>b;
    ll xa=1,xb=1;
    ll ya=1,yb=1;
    for(ll i=0;i<a;i++){
        xa=xa*(n-i)%MOD;
        ya=ya*(i+1)%MOD;
    }
    for(ll i=0;i<b;i++){
        xb=xb*(n-i)%MOD;
        yb=yb*(i+1)%MOD;
    }
    ll ans=modpow(2,n)-1-xa*modpow(ya,MOD-2)%MOD-xb*modpow(yb,MOD-2)%MOD;
  while(ans<0) ans+=MOD;
  cout<<ans<<endl;
    return 0;
}