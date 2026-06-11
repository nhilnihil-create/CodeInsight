#include<bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;
long long dp[2100][2100];

int main(){
    int N,M; cin >> N >> M;
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    int s[N],t[M];
    for(int i=0;i<N;i++) cin >> s[i];
    for(int i=0;i<M;i++) cin >> t[i];
    for(int i=0;i<N+1;i++){
        for(int j=0;j<M+1;j++){
            if(i>0&&j>0&&s[i-1]==t[j-1]){
                dp[i][j]+=dp[i-1][j-1];
            }
            if(i>0) dp[i][j]+=dp[i-1][j];
            if(j>0) dp[i][j]+=dp[i][j-1];
            if(i>0&&j>0) dp[i][j]+=(MOD-dp[i-1][j-1])%MOD;
            dp[i][j]%=MOD;
        }
    }
    cout << dp[N][M] << endl;
}