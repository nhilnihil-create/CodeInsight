#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;
#define INF 1e9
int main() {
    int N,M; cin>>N>>M;
    vi cost(M);
    vi key_spec(M,0);
    for (int i = 0; i < M; i++){
        int a,b; cin>>a>>b;
        cost[i]=a;
        for (int j = 0; j < b; j++){
            int c; cin>>c;
            key_spec[i]+=(1 << (c-1));
        }
    }
    
    vector<vi> dp(M,vi((1 << N), INF));
    dp[0][0]=0;
    for (int i = 0; i < M; i++){
        for (int j = 0; j < (1 << N); j++){
            if(i==0){
                if(j==key_spec[0])dp[i][j]=cost[i];
            }else{
                dp[i][j | key_spec[i]]=min(dp[i][j | key_spec[i]],dp[i-1][j]+cost[i]);
                dp[i][j]=min(dp[i][j],dp[i-1][j]);
            }
        }
    }
    if(dp[M-1][(1<<N)-1]==INF)dp[M-1][(1<<N)-1]=-1;
    cout<<dp[M-1][(1<<N)-1]<<endl;
}