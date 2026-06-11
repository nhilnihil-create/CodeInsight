//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#include "boost/multiprecision/cpp_int.hpp"
//typedef boost::multiprecision::cpp_int ll;
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
typedef pair<dd,dd> d_d;
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fi first
#define se second
#define endl "\n"
///////////////////////////


int main(){fastio
    ll n;cin>>n;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    ll pos[n+1];
    rep(i,0,n-1){
        pos[a[i]]=i;
    }
    vector<ll>idx;
    rep(i,0,n-1)idx.pb(a[i]);
    sort(idx.rbegin(),idx.rend());
    set<ll>s;
    ll l1[n+1],l2[n+1],r1[n+1],r2[n+1];
    rep(i,1,n){
        l2[i]=inf;r2[i]=-inf;
        l1[i]=0;r1[i]=0;
    }
    for(auto val:idx){
        s.insert(pos[val]);
        auto itr=s.lower_bound(pos[val]);
        ll laspos=*itr;
        ll newpos;
        if(itr==s.begin()){
            newpos=-1;
            l1[val]=(laspos-newpos);
        }else{
            itr--;
            newpos=*itr;
            l1[val]=laspos-newpos;
            laspos=newpos;
            if(itr==s.begin())newpos=-1;
            else {itr--;newpos=*itr;}
            l2[val]=laspos-newpos;
        }
        itr=s.lower_bound(pos[val]);
        laspos=*itr;
        itr++;
        if(itr==s.end()){
            newpos=n;
            r1[val]=newpos-laspos;
        }else{
            newpos=*itr;
            r1[val]=newpos-laspos;
            laspos=newpos;
            itr++;
            if(itr==s.end())newpos=n;
            else newpos=*itr;
            r2[val]=newpos-laspos;
        }
    }
    /*
    rep(i,1,n){
        cout<<l1[i]<<" "<<l2[i]<<" "<<r1[i]<<" "<<r2[i]<<endl;
    }*/
    ll ans=0;
    rep(i,1,n){
        if(r2[i]!=-inf){
            ans+=i*l1[i]*r2[i];
        }
        if(l2[i]!=inf){
            ans+=i*r1[i]*l2[i];
        }
    }
    cout<<ans<<endl;
    
    return 0;
}
