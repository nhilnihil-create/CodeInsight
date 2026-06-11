#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;++i)
#define P pair<ll,ll>
#define Graph vector<vector<P>>
#define fi first
#define se second
constexpr ll mod=1000000007;
constexpr ll INF=(1ll<<60);
constexpr double pi=3.14159265358979323846;
template<typename T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<typename T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}

int main(){
    ll n;cin>>n;
    vector<ll> h(n);
    ll MAX=0,MIN=INF;
    rep(i,n){
        cin>>h[i];
    }

    rep(i,n-1){
        if(i==0){
            h[i]--;
            continue;
        }
        if(h[i-1]<h[i]) h[i]--;
    }

    bool can=true;
    rep(i,n-1){
        if(h[i]>h[i+1]) can=false;
        //cout<<h[i]<<" ";
    }
    //cout<<h[n-1]<<endl;

    if(can) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
    return 0;
}