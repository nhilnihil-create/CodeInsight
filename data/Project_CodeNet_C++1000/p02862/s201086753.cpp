#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
using ll = long long;
using namespace std;

const int mod = 1000000007;
ll modpow(ll a,ll n){
    ll res=1;
    while(n>0){
        if(n&1){
            res=res*a%mod;
        }
        a=a*a%mod;
        n>>=1;
    }
    return res;
}
ll modchoose(int n,int a){
    ll x=1,y=1;
    rep(i,a){
        x=(x*(n-i))%mod;
        y=(y*(i+1))%mod;
    }
    return (x*modpow(y,mod-2))%mod; // x/y
}
int main(){
    ll x,y;
    cin>>x>>y;
    ll ans=0;
    ll a=(2*x-y)/3;
    ll b=(2*y-x)/3;
    if((2*x-y)%3!=0||(2*y-x)%3!=0||a<0||b<0){
        ans=0;
    }
    else if(a+2*b==y&&2*a+b==x){
        //cout<<a<<" "<<b<<endl;
        ans=modchoose(a+b,min(a,b))%mod;
    }
    cout<<ans<<endl;
}
