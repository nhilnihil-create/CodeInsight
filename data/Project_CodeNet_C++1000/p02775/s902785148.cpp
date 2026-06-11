#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
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
    string s;cin>>s;
    int dp[SZ(s)+1][2];
	REP(i,2)dp[0][i]=0;
    REP(i,SZ(s)){
        int d=s[i]-'0';
        dp[i+1][0]=min(dp[i][0]+d,dp[i][1]+d+2);
        dp[i+1][1]=min(dp[i][0]+9-d,dp[i][1]+9-d);
    }
    cout<<min(dp[SZ(s)][0],dp[SZ(s)][1]+2)<<endl;
}