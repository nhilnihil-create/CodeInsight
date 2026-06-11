#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
const int N =1e5+6;
const int mod = 1e9+7;
ll po(ll a,ll b){
    if(b==0)return 1;
    ll x = po(a,b/2);
    x = (x*x)%mod;
    if(b&1)x = (x*a)%mod;
    return x;
}
void solve(){
   ll n,a,b;;
   cin>>n>>a>>b;
   ll ans = po(2,n);
   ll trt1 = 1;
   for(int i=0;i<a;i++){
        trt1*=(n-i);
        trt1%=mod;
   }
   ll trt2 = 1;
   for(int i=1;i<=a;i++){
        trt2*=(i);
        trt2%=mod;
   }
   trt2 = po(trt2,mod-2);
   trt1 = (trt1*trt2)%mod;
   ans = ((ans-trt1)%mod+mod)%mod;
   trt1 = 1;
   for(int i=0;i<b;i++){
        trt1*=(n-i);
        trt1%=mod;
   }
   trt2 = 1;
   for(int i=1;i<=b;i++){
        trt2*=(i);
        trt2%=mod;
   }
   trt2 = po(trt2,mod-2);
   trt1 = (trt1*trt2)%mod;
   ans = ((ans-trt1-1)%mod+mod)%mod;
   cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;
    while(t--)solve();
    return 0;
}
