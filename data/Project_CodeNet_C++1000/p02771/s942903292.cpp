#include<bits/stdc++.h>
using namespace std;
#define ll int64_t
#define rep(i,n) for(int64_t i=0;i<n;++i)
#define P pair<ll,ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
constexpr int64_t INF=(1ll<<60);
constexpr int64_t mod=1000000007;
constexpr double pi=3.14159265358979323846;
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    vector<ll> san(3);
    rep(i,3) cin>>san[i];

    sort(san.begin(),san.end());

    bool yes=false;
    if(san[0]==san[1] && san[1]!=san[2]) yes=true;
    if(san[0]!=san[1] && san[1]==san[2]) yes=true;

    if(yes) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}