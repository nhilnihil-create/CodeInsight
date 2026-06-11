#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll mod = 1e9+7;

int main(){
    int N, M;
    cin >> N >> M;
    vector<ll> S(N+1, 0), T(M+1, 0);
    for (int i = 1; i <= N; i++) cin >> S[i];
    for (int i = 1; i <= M; i++) cin >> T[i];
    vector<vector<ll>> dp(N+1, vector<ll>(M+1, 0));
    for (int i = 0; i <= N; i++) dp[i][0] = 1;
    for (int j = 0; j <= M; j++) dp[0][j] = 1;
    //dp[i][j] = #{S[1..i]の部分列とT[1..j]の部分列で一致するものの総数}
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
            if (S[i] == T[j]) dp[i][j] += dp[i-1][j-1];
            dp[i][j] = (dp[i][j] + mod) % mod;
            //cout << i << j << " " << dp[i][j] << endl;
        }
    }
    cout << dp[N][M] << endl;
    return 0;
}