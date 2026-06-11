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
    vector<ll> d(n);
    rep(i,n) cin>>d[i];

    ll sum=0;
    rep(i,n-1){
        for(ll j=i+1;j<n;j++){
            sum+=d[i]*d[j];
        }
    }
    cout<<sum<<endl;
    return 0;
}