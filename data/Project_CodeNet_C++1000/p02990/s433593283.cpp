#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long; 
using P=pair<int,int>;
using lP=pair<ll,ll>;
using fP=pair<double,double>;
ll const mod=1e9+7;
ll pow(ll a,ll b){
    ll r=1;
    while(b>0){
        if(b%2==1)r=r*a%mod;
        a=a*a%mod;
        b/=2;
    }
    if(r<0)cout<<"rrr"<<r<<endl;
    return r;
}
ll c(ll a,ll b){
    ll x=1,y=1;
    rep(i,b){
        x*=(a-i);
        x%=mod;
        y*=(b-i);
        y%=mod;
    }
    if(x<0||y<0)cout<<x<<" "<<y<<endl;
    ll res= x*pow(y,mod-2)%mod;
    res%=mod;
    if(res<0)cout<<res<<endl;
    return res;
}
ll f(ll a,ll b){
    if(a>0&&b==0)return 0;
    if(b>a)return 0;
    if(b==a)return 1;
    return c(a-1,b-1);
}

int main(){
    ll n,k;
    cin>>n>>k;
    ll ans;
    arep(i,1,k+1){
        ll blue=f(k,i);
        //cout<<"blue"<<blue<<endl;
        blue%=mod;
        ll red=0;
        red+=f(n-k,i-1);
        red%=mod;
        red+=f(n-k,i);
        red%=mod;
        red+=f(n-k,i);
        red%=mod;
        red+=f(n-k,i+1);
        red%=mod;

        ans=red*blue%mod;
        cout<<ans<<endl;

    }
   
    return 0;
}