#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define P pair<ll, ll>
#define Graph vector<vector<P>>
#define fi first
#define se second
constexpr ll mod = 1000000007;
constexpr ll INF = (1ll << 60);
constexpr double pi = 3.14159265358979323846;
template <typename T>inline bool chmax(T &a, T b){if (a < b){a = b;return 1;}return 0;}
template <typename T>inline bool chmin(T &a, T b){if (a > b){a = b;return 1;}return 0;}

int main(){
    ll ans=0,n;cin>>n;
    vector<ll> a(n),c(n-1);
    rep(i,n){
        cin>>a[i];    
        a[i]--;
    }
    rep(i,n){
        ll b;cin>>b;
        ans+=b;
    }
    rep(i,n-1) cin>>c[i];

    rep(i,n-1){
        if(a[i]+1==a[i+1]) ans+=c[a[i]];
    }

    cout<<ans<<endl;

    return 0;
}