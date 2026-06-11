#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_ll.hpp>
//typedef boost::multiprecision::cpp_ll ll;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E18;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define endl "\n"
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


ll hpow(ll x,ll y){
    ll ans=1;
    ll i=x;
    if(y==0)return 1;
    while(y>0){
        if(y%2==1){
            ans=(ans*i)%i_7;
        }
        i=(i*i)%i_7;
        y=y/2;
        
    }
    return ans;
}
ll comb(ll n,ll k){
    ll a=1;
    ll b=1;
    for(ll i=n;i>=n-k+1;i--){
        a=mod(a*i);
    }
    rep(i,1,k){
        b=mod(b*i);
    }
    b=hpow(b,i_7-2);
    return mod(a*b);
}

int main(){fastio
    ll s;cin>>s;
    ll ans=0;
    rep(i,1,s){
        ll n=s-i*3;
        if(n<0)break;
        ans=mod(ans+comb(n+i-1,i-1));
    }
    cout<<ans<<endl;
    return 0;
}



