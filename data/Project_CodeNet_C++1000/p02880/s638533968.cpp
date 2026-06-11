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
    bool yes=false;
    for(ll i=1;i<=9;i++){
        for(ll j=1;j<=9;j++){
            if(n==i*j) yes=true;
        }
    }

    if(yes) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}