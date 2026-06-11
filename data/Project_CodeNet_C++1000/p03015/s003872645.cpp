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

int mul(int x,int y){
    x=x*y%MOD;
    return x;
}

signed main(){
    string l;cin>>l;
    int dp[SZ(l)+1][2];
    REP(i,SZ(l)+2)REP(j,2)dp[i][j]=0;
    dp[0][0]=1;
    REP(i,SZ(l)){
        int d=l[i]-'0';
        if(d==0){
            dp[i+1][1]=mul(dp[i][1],3);
            dp[i+1][0]=dp[i][0];
        }
        else{
            dp[i+1][1]=(mul(dp[i][1],3)+dp[i][0])%MOD;
            dp[i+1][0]=mul(dp[i][0],2);
        }
    }
    cout<<(dp[SZ(l)][0]+dp[SZ(l)][1])%MOD<<endl;
}