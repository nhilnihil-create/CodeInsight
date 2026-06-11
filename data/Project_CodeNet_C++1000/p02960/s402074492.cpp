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
    string S;cin>>S;
    int N=S.size();
    int dp[N+1][13];
    REP(i,N+1)REP(j,13)dp[i][j]=0;
    REP(i,N){
        int d=(S[i]!='?'?S[i]-'0':-1);
        if(i==0){
            if(d!=-1) dp[1][d]=1;
            else REP(j,10)dp[1][j]=1;
        }
        else{
            if(d!=-1){
                REP(j,13)dp[i+1][(j*10+d)%13]=dp[i][j]%MOD;
            }
            else {
                REP(e,10)REP(j,13){
                  	dp[i+1][(j*10+e)%13]+=dp[i][j];
                  	dp[i+1][(j*10+e)%13]%=MOD;
                }
            }
        }
    }
    cout<<dp[N][5]%MOD<<endl;
}