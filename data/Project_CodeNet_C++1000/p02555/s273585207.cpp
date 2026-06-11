#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int maxn=1e5+5,mod=1e9+7,inf=0x3f3f3f3f;
ll ans,s;
ll fac[maxn],inv[maxn];
ll qpow(ll a,ll b){
    ll ans=1,base=a;
    while(b){
        if(b&1){
            ans=ans*base%mod;
        }
        base=base*base%mod;
        b=b>>1;
    }
    return ans;
}
ll cal(ll a,ll b){
//    if(a<b) return 0;
    return fac[a]*inv[b]%mod*inv[a-b]%mod;
}
int main(){
    fac[0]=inv[0]=1;
    for(int i=1;i<=4000;i++){
        fac[i]=fac[i-1]*i%mod;
        inv[i]=qpow(fac[i],mod-2);
    }
    scanf("%lld",&s);
    for(int i=1;i<=s/3;i++){
        ll rest=s-i*3;
//        cout<<rest<<endl;
//        cout<<i+rest-1<<" "<<i-1<<endl;
        ans=(ans+cal(i+rest-1,i-1))%mod;
    }
    printf("%lld\n",ans);
    return 0;
}
