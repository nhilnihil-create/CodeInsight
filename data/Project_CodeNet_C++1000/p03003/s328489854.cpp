#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
using LP=pair<ll,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;



int main() {
    int N,M;
    cin>>N>>M;
    vector<int> S(N),T(M);
    rep(i,N)cin>>S.at(i);
    rep(i,M)cin>>T.at(i);
    vector<vector<ll>> dp(N+1,vector<ll> (M+1));
    rep(i,N){
        if(S.at(i)==T.at(0)){
            dp[i][0]=1;
        }
    }
    rep(i,N)dp[i+1][0]+=dp[i][0];
    rep(i,M){
        if(T.at(i)==S.at(0)){
            dp[0][i]=1;
        }
    }
    rep(i,M)dp[0][i+1]+=dp[0][i];
    for(int i=1;i<N;i++){
        for(int j=1;j<M;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            if(S.at(i)==T.at(j)){
                dp[i][j]+=dp[i-1][j-1]+1;
            }
            dp[i][j]%=MOD;
            if(dp[i][j]<0)dp[i][j]+=MOD;
        }
    }
    cout<<dp[N-1][M-1]+1<<endl;
    /*rep(i,N){
        rep(j,M){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
}