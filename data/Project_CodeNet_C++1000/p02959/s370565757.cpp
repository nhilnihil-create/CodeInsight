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
    vector<ll> a(n+1),b(n);
    ll before=0;
    rep(i,n+1){
        cin>>a[i];
        before+=a[i];
    }
    rep(i,n) cin>>b[i];
    
    rep(i,n){
        ll retain=a[i];
        a[i]=max(0ll,a[i]-b[i]);
        b[i]=max(0ll,b[i]-retain);

        a[i+1]=max(0ll,a[i+1]-b[i]);
    }

    ll after=0;
    rep(i,n+1) after+=a[i];

    cout<<before-after<<endl;
    return 0;
}