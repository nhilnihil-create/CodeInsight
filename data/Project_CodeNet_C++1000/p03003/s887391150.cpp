#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main(void){
    int N, M;
    cin >> N >> M;

    vector<int> S(N, 0);
    vector<int> T(M, 0);

    for(int i=0; i<N; i++)cin >> S[i];
    for(int i=0; i<M; i++)cin >> T[i];

    vector<vector<long long>> dp(N, vector<long long>(M, 0LL));
    vector<vector<long long>> sum(N, vector<long long>(M, 0LL));

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(S[i] == T[j]){
                if((i>0)&&(j>0)){
                    dp[i][j] = sum[i-1][j-1]+1;
                }else dp[i][j] = 1;
                dp[i][j] = dp[i][j] % MOD;
            }else dp[i][j] = 0;
            if(i>0){
                if(j>0){
                    sum[i][j] = ((sum[i-1][j] + sum[i][j-1])%MOD + (MOD-sum[i-1][j-1]))%MOD+ dp[i][j];
                }else sum[i][j] = sum[i-1][j] + dp[i][j];
            }else if(j>0){
                sum[i][j] = sum[i][j-1] + dp[i][j];
            }else{
                sum[i][j] = dp[i][j];
            }
            sum[i][j] = sum[i][j] % MOD;
        }
    }

    cout << sum[N-1][M-1]+1 << endl;

    return 0;
}