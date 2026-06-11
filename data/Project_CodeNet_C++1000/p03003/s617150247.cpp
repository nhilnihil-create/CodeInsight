#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

const long long MOD = 1000000007;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repn(i, n) for(int i = 1; i <= n; i++) 

int main(){
    int N, M; cin >> N >> M;
    int S[N+1], T[M+1];
    repn(i, N) cin >> S[i];
    repn(i, M) cin >> T[i];

    long long dp[N+2][M+2];
    rep(i, N+1) dp[i][0] = 0;
    rep(j, M+1) dp[0][j] = 0;
    repn(i, N) repn(j, M){
        if(S[i] == T[j])
            dp[i][j] = (dp[i-1][j] + dp[i][j-1] + 1 + MOD) % MOD;
        else
            dp[i][j] = (dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + MOD) % MOD;
    }
    cout << (dp[N][M]+1)%MOD << endl;
}
