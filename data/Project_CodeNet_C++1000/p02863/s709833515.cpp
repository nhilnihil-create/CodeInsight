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
    ll n,t;cin>>n>>t;
    vector<P> T(n);
    ll MAX=0;
    rep(i,n){
        cin>>T[i].fi>>T[i].se;
        chmax(MAX,T[i].fi);
    }
    sort(T.begin(),T.end());

    //i-1番目の料理まで選択可能 時間がj分以内　この時のmax
    vector<vector<ll>> dp(3010,vector<ll>(6010,-1));
    dp[0][0]=0;

    rep(i,n){
        rep(j,t){
            if(dp[i][j]==-1) continue;
            
            //i番目を食べるとき
            chmax(dp[i+1][j+T[i].fi],dp[i][j]+T[i].se);
        
            //i番目を食べないとき
            chmax(dp[i+1][j],dp[i][j]);
        }
    }

    ll ans=0;
    rep(i,3010){
        rep(j,6010){
            chmax(ans,dp[i][j]);
        }
    }

    cout<<ans<<endl;
    return 0;
}