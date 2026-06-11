#include <bits/stdc++.h>
//#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#include "boost/multiprecision/cpp_int.hpp"
//typedef boost::multiprecision::cpp_int LL;
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
#define SORT(v) sort(v.begin(),v.end())
#define ERASE(v) v.erase(unique(v.begin(),v.end()),v.end())
#define POSL(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define POSU(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
//template<class T>void max(T a,T b){if(a<b)return b;else return a;}
//template<class T>void min(T a,T b){if(a>b)return b;else return a;}
//template<class T>bool Max(T&a, T b){if(a < b){a = b;return 1;}return 0;}
//template<class T>bool Min(T&a, T b){if(a > b){a = b;return 1;}return 0;}

//////////////////////////

ll cal(string s){
    ll res=0;
    ll n=s.size();
    rep(i,0,n-1){
        res+=(1<<i)*(s[n-1-i]-'0');
    }
    return res;
}

void solve(string s){
    ll n=cal(s);
    ll cnt=0;
    rep(a,0,n){
        rep(b,0,n){
            if(a+b<=n&&(a^b)==(a+b)){
                cout<<a<<" "<<b<<endl;
            }
        }
    }
    cout<<cnt<<endl;
}


int main(){fastio
    
    
    string s;cin>>s;
    //solve(s);
    ll n=s.size();
    ll dp[n][2];memset(dp,0,sizeof(dp));
    dp[0][0]=1;dp[0][1]=2;
    rep(i,1,n-1){
        if(s[i]=='0'){
            Add(dp[i][0],dp[i-1][0]*3);
            Add(dp[i][1],dp[i-1][1]*1);
        }else{
            Add(dp[i][0],dp[i-1][0]*3);
            Add(dp[i][0],dp[i-1][1]);
            Add(dp[i][1],dp[i-1][1]*2);
        }
    }
    /*
    rep(i,0,n-1){
        rep(j,0,1)cout<<dp[i][j]<<" ";cout<<endl;
    }*/
    ll ans=mod(dp[n-1][0]+dp[n-1][1]);
    cout<<ans<<endl;
    
    return 0;
}
