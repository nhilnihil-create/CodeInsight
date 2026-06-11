#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,a,b;
ll ans;
ll A=1,B=1,C=1,D=1;
const ll MOD=1000000007;
ll modpow(ll a,ll n,ll MOD){
    ll res=1;
    while(n>0){
        if(n&1) res=res*a%MOD;
        a=a*a%MOD;
        n>>=1;
    }
    return res;
}
ll modinv(ll a,ll MOD) {
    ll b=MOD,u=1,v=0;
    while(b){
        ll t=a/b;
        a-=t*b; swap(a,b);
        u-=t*v; swap(u,v);
    }
    u%=MOD; 
    if(u<0) u+=MOD;
    return u;
}
int main(void){
    cin>>n>>a>>b;
    ans=modpow(2,n,MOD)-1;
    for(int i=0;i<a;i++){
        A=(A*(n-i))%MOD;
        C=(C*(i+1))%MOD;
    }
    for(int i=0;i<b;i++){
        B=(B*(n-i))%MOD;
        D=(D*(i+1))%MOD;
    }
    C=modinv(C,MOD); D=modinv(D,MOD);
    ans=(ans-(A*C)%MOD-(B*D)%MOD)%MOD;
    if(ans<0) ans+=MOD;
    cout<<ans<<endl;


}
