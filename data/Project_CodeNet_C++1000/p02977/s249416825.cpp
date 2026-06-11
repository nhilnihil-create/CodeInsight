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
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
//template<class T>void max(T a,T b){if(a<b)return b;else return a;}
//template<class T>void min(T a,T b){if(a>b)return b;else return a;}
//template<class T>bool Max(T&a, T b){if(a < b){a = b;return 1;}return 0;}
//template<class T>bool Min(T&a, T b){if(a > b){a = b;return 1;}return 0;}

//////////////////////////

ll cal(ll n){
    ll res=1;
    while(res*2<=n){
        res*=2;
    }
    return res;
}
vector<l_l>ans;

bool solve(){
    ll n;cin>>n;
    //cout<<__builtin_popcount(n)<<endl;
    if(__builtin_popcount(n)==1){
        cout<<"No"<<endl;
        return 0;
    }
    
    rep(i,1,5){
        ll j=i+1;
        ll si=i,sj=j;
        if(i>=4)si=i-3+n;
        else si=i;
        if(j>=4)sj=j-3+n;
        else sj=j;
        ans.pb({si,sj});
    }
    for(ll i=4;i<=n-1;i+=2){
        ans.pb({i,i+1});
        ans.pb({i+1,1});
        ans.pb({1,i+n});
        ans.pb({i+n,i+n+1});
    }
    if(n%2==0){
        ll c=cal(n);
        ll e=n+1-c;
        if(e==3){
            ans.pb({n-1,n});
            ans.pb({2,n*2});
        }else{
            ans.pb({n,c+n});
            ans.pb({2*n,e});
        }
    }
    cout<<"Yes"<<endl;
    
    for(auto x:ans){
        cout<<x.fi<<" "<<x.se<<endl;
    }
    return 0;
}
int main(){fastio
    solve();
    return 0;
}
