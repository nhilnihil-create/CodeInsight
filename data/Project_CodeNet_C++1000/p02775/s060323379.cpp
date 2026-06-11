#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
const int MOD=1e9+7;
const int INF=1e15;

signed main(){
    string S;cin>>S;
    bool kurisage=false;
    int dp[S.size()+1][2];
    //0はピッタリ払う
    //1は1多く払う
    REP(i,S.size()){
        int d=S[i]-'0';
      	if(i==0){
            dp[i+1][0]=d;
            dp[i+1][1]=9-d;
        }
        else{
            dp[i+1][0]=min(dp[i][0]+d,dp[i][1]+d+2);
            dp[i+1][1]=min(dp[i][0]+9-d,dp[i][1]+9-d);
        }
    }
    int ans=min(dp[S.size()][0],dp[S.size()][1]+2);
    cout<<ans<<endl;
}