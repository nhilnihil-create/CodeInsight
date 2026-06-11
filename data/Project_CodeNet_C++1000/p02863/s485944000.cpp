#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
int main() {
    int N,T;cin>>N>>T;
    vi A(N),B(N);
    for (int i = 0; i < N; i++){
        cin>>A[i]>>B[i];
    }
    vector<vector<vi>> dp(T,vector<vi>(N,vi(2,0)));
    for (int t = 0; t < T; t++){
        for (int i = 0; i < N; i++){
            //食べる
            if(t+A[i]<T){
                if(i!=0){
                    dp[t+A[i]][i][0]=max(dp[t+A[i]][i][0],dp[t][i-1][0]+B[i]);
                    dp[t+A[i]][i][1]=max(dp[t+A[i]][i][1],dp[t][i-1][1]+B[i]);
                }else if(i==0){
                    dp[t+A[i]][i][0]=max(dp[t+A[i]][i][0],B[i]);
                    dp[t+A[i]][i][1]=max(dp[t+A[i]][i][1],B[i]);
                }
            }
            //食べない
            if(i!=0){
                dp[t][i][0]=max(dp[t][i][0],dp[t][i-1][0]);
                dp[t][i][1]=max(dp[t][i][1],dp[t][i-1][1]);
                //デザート
                dp[t][i][1]=max(dp[t][i][1],dp[t][i-1][0]+B[i]);
            }
            if(t!=0){
                dp[t][i][0]=max(dp[t][i][0],dp[t-1][i][0]);
                dp[t][i][1]=max(dp[t][i][1],dp[t-1][i][1]);
            }
        }
    }
    cout<<dp[T-1][N-1][1]<<endl;
}