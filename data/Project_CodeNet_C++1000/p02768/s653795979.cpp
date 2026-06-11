#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9+7
#define rep(i,n) for(ll i=0;i<n;i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
const int maxn = 1000000;
const int maxa = 200000;
ll mod = INF;

ll ans;
ll n,a,b;

ll mpow(ll x,ll y){
    if(y==0){
        return 1;
    }else if(y==1){
        return x;
    }else if(y%2==0){
        ll a=mpow(x,y/2)%mod;
        return (a*a)%mod;
    }else{
        ll a=mpow(x,(y-1)/2)%mod;
        return ((a*a)%mod*x)%mod;
    }
}

int main(){

    cin >> n>>a>>b;
    ans=mpow(2,n);
    ans-=1;

    ll s=1;
    for(ll i=0;i<a;i++){
        s=s*(n-i)%mod;
    }
    ll t=1;
    for(ll i=1;i<=a;i++){
        t=t*i%mod;
    }
    t=mpow(t,mod-2);
    s=s*t%mod;

    ans-=s;
    while(ans<0)ans+=mod;
    ////
    s=1;
    for(ll i=0;i<b;i++){
        s=s*(n-i)%mod;
    }
    t=1;
    for(ll i=1;i<=b;i++){
        t=t*i%mod;
    }
    t=mpow(t,mod-2);
    s=s*t%mod;

    ans-=s;
    while(ans<0)ans+=mod;

    cout << ans<<endl;
    return 0;
}