#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int (i)=0;(i) < (N); (i)++)
#define all(V) V.begin(), V.end()
using i64 = int_fast64_t;
using P = pair<int,int>;

int main(){
    int N, M;
    cin >> N >> M;
    
    vector<int> S(N);
    vector<int> T(M);

    rep(i, N) cin >> S[i];
    rep(i, M) cin >> T[i];

    vector<vector<i64>> dp(N+1, vector<i64>(M+1, 0));
    rep(i, N+1) dp[i][0] = 1;
    rep(i, M+1) dp[0][i] = 1;

    const i64 MOD = 1e9 + 7;
    for(int i = 1; i <= N; i++ ){
        for(int j = 1; j <= M; j++){
            i64 diff = (dp[i-1][j] + dp[i][j-1]) % MOD;
            diff -= dp[i-1][j-1];
            if(diff < 0) diff += MOD;
            (dp[i][j] += diff) %= MOD;
            if(S[i-1] == T[j-1]) (dp[i][j] += dp[i-1][j-1]) %= MOD;
        }
    }

    cout << dp[N][M] << endl;
}
