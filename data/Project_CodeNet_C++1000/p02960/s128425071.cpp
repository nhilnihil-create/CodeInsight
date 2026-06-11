#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define int long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
const int MOD=1e9+7;
const int INF=1e15;

signed main(){
    string S;cin>>S;
    int N=S.size();
    vector<vector<int>>dp(N+1,vector<int>(13,0));
    REPS(i,N){
        int d=S[i-1]-'0';
        if(i==1){
            if(S[0]!='?')dp[1][d]++;
            else{
                REP(i,10)dp[1][i]++;
            }
        }
        else{
            if(S[i-1]!='?'){
                REP(j,13){
                    dp[i][(j*10+d)%13]+=dp[i-1][j];
                    dp[i][(j*10+d)%13]%=MOD;
                }
            }
            else{
                REP(dz,10){
                    REP(j,13){
                        dp[i][(j*10+dz)%13]+=dp[i-1][j];
                        dp[i][(j*10+dz)%13]%=MOD;
                    }
                }
            }  
        }
    }
    cout<<dp[N][5]<<endl;
}