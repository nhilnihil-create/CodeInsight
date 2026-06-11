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

vector<ll> yak;
void yakusuu(ll x){
    for(ll i=1;i*i<=x;i++){
        if(x%i==0){
            yak.push_back(i);
            if(i*i!=x){
                yak.push_back(x/i);
            }
        }
    }
    sort(yak.begin(),yak.end(),greater<ll>());
}

int main(){fastio
    ll n,k;cin>>n>>k;
    ll a[n];
    ll a_sum=0;
    rep(i,0,n-1){
        cin>>a[i];
        a_sum+=a[i];
    }
    yakusuu(a_sum);
    rep(i,0,yak.size()-1){
        vector<ll> q;
        rep(j,0,n-1){
            if(a[j]%yak[i]!=0){
                q.pb((a[j]%yak[i]+yak[i])%yak[i]);
            }
        }
        if(q.size()==0){
            cout<<yak[i]<<endl;
            return 0;
        }
        sort(q.begin(),q.end());
        ll q_sum=0;
        rep(i,0,q.size()-1){
            q_sum+=q[i];
        }
        ll d=q_sum/yak[i];
        ll sco=0;
        rep(i,0,(ll)q.size()-d-1){
            sco+=q[i];
        }
        if(sco<=k){
            cout<<yak[i]<<endl;
            return 0;
        }
    }
    
    
    return 0;
}



