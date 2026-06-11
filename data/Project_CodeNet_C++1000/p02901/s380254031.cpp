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

signed main(){
    int N,M;cin>>N>>M;
    int dp[(1<<N)];
    REP(i,(1<<N))dp[i]=INF;
    dp[0]=0;
    REP(i,M){
        int a,b;cin>>a>>b;
      	int now=0;
        REP(j,b){
            int c;cin>>c;c--;
            now+=(1<<c);
        }
        for(int k=0;k<(1<<N);k++) chmin(dp[(k|now)],dp[k]+a);
    }
    int ans=dp[(1<<N)-1];
    cout<<(ans!=INF?ans:-1)<<endl;
}