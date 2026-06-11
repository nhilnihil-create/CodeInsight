#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,N-1,0)
#define RREPS(i,n) RFOR(i,N,1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
const int INF=1e18;
const int MOD=1e9+7;

signed main(){
    int N,T;cin>>N>>T;
    vector<pair<int,int>>vec(N);
    REP(i,N){
        int a,b;cin>>a>>b;
        vec[i]={a,b};
    }
    sort(all(vec));
    int dp[N+1][T+3000];
  	REP(i,N+1)REP(j,T+3000)dp[i][j]=0;
    REP(i,N){
        REP(j,T){
            chmax(dp[i+1][j+vec[i].first],dp[i][j]+vec[i].second);
            chmax(dp[i+1][j],dp[i][j]);
        }
    }
    int ans=0;
    REP(i,N+1)REP(j,T+3000)chmax(ans,dp[i][j]);
    cout<<ans<<endl;
}