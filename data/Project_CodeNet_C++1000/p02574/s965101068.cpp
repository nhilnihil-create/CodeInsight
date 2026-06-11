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

ll era[1000001];    //era[i]=iを割り切る最小の素数
void era_init(){
    era[1]=1;
    rep(i,2,1000000){
        if(era[i]==0){
            era[i]=i;
            for(ll j=i*2;j<=1000000;j+=i){
                if(era[j]==0)era[j]=i;
            }
        }
    }
}
map<ll,ll> prime_fac(ll x){
    map<ll,ll> mp;
    while(x>1){
        ll d=era[x];
        auto itr=mp.find(d);
        if(itr==mp.end()){
            mp[d]=1;
        }else{
            mp[d]++;
        }
        x/=d;
    }
    return mp;
}
ll gcd(ll x,ll y){
    if(x<y) return gcd(y,x);
    if(y==0) return x;
    return gcd(y,x%y);
}


int main(){fastio
    ll n;cin>>n;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    era_init();
    set<ll> st;
    bool b[2];rep(i,0,1)b[i]=false;
    rep(i,0,n-1){
        map<ll,ll> mp=prime_fac(a[i]);
        for(auto itr=mp.begin();itr!=mp.end();++itr){
            if(st.find(itr->first)!=st.end()){
                b[0]=true;
            }
            st.insert(itr->first);
        }
    }
    ll g=a[0];
    rep(i,1,n-1){
        g=gcd(g,a[i]);
    }
    if(g!=1)b[1]=true;
    if(!b[0]){
        cout<<"pairwise coprime"<<endl;
    }else if(!b[1]){
        cout<<"setwise coprime"<<endl;
    }else{
        cout<<"not coprime"<<endl;
    }
    

    return 0;
}



