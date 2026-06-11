#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
using ll = long long;
int mod = 1000000007;

int main(void){
    int N, M; cin >> N >> M;
    int S[N+1] = {}; rep(i, N) cin >> S[i+1];
    int T[M+1] = {}; rep(i, M) cin >> T[i+1];
    //dp[i][j]: S[0]-S[i], T[0]-T[j]まで考えた時の一致する部分列の個数
    //dp[i][j]とdp[i][j+1]を考えると, dp[i][j+1] = dp[i][j] + (T[j+1]で終わる部分列の個数)
    //ようはT[j+1]を使うということ
    //S[k] = T[j+1]となるような最大のk(k <= i)を考えると
    //(S[i]まででT[j+1]で終わる部分列の一致個数)はdp[k-1][j]のはず -> ほんまか? -> うそ
    //(S[i]まででT[j+1]で終わる部分列の一致個数)T[j+1]のSにおける出現リストを{k1, k2,...}とすると
    //dp[k1-1][j] + dp[k2-1][j] + ...となる
    //しかしdp[i-1][j+1]でもほぼ同じ計算をするので,この結果が使える
    //dp[i-1][j+1] = dp[i-1][j] + (S[i-1]まででT[j+1]で終わる部分列の一致個数)
    //よってS[i] != T[j+1]ならdp[i-1][j+1] - dp[i-1][j],
    //S[i] == T[j+1]なら(dp[i-1][j+1] - dp[i-1][j]) + dp[i-1][j] = dp[i-1][j+1]が(S[i]まででT[j+1]で終わる部分列の一致個数)
    ll dp[N+1][M+1];
    rep(i, N+1) rep(j, M+1) dp[i][j] = 0;
    dp[0][0] = 1;
    rep(i, N) dp[i+1][0] = 1;
    rep(j, M) dp[0][j+1] = 1;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= M-1; j++){
            if(S[i] == T[j+1]) dp[i][j+1] = (dp[i][j] + dp[i-1][j+1]) % mod;
            else dp[i][j+1] = (dp[i][j] + (dp[i-1][j+1] - dp[i-1][j])) % mod;
        }
    }
    if(dp[N][M] < 0) dp[N][M] += mod;
    cout << dp[N][M] << endl;
    return 0;
}