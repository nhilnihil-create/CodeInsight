#include<iostream>

#define DIV 1000000007

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    int S[N+1], T[M+1];
    for(int i=0; i<N; i++){
        cin >> S[i];
    }
    S[N] = -1;
    for(int i=0; i<M; i++){
        cin >> T[i];
    }
    T[M] = -1;

    long dp[N+1][M+1];
    long sum[N+1][M+1];
    for(int i=0; i<N+1; i++){
        fill(dp[i], dp[i] + M + 1, 0);
    }
    for(int i=0; i<N+1; i++){
        fill(sum[i], sum[i] + M + 1, 0);
    }

    for(int i=0; i<N+1; i++){
        for(int j=0; j<M+1; j++){
            if(i == 0 || j == 0){
                dp[i][j] = long(S[i] == T[j]);
                sum[i][j] = 0;
            }
            else{
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + dp[i-1][j-1] + DIV;
                sum[i][j] %= DIV;
                if(S[i] == T[j]){
                    dp[i][j] = sum[i][j] + 1;
                    dp[i][j] %= DIV;
                }
            }
        }
    }

    cout << dp[N][M] << endl;
    return 0;
}