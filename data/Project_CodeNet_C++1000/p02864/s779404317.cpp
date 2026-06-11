#include <bits/stdc++.h>
using namespace std;

void chmin(int64_t& a, int64_t b){
    a = min(a, b);
}

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> H(N+1);
    for(int i=1; i<=N; i++) cin >> H[i];

    static int64_t dp[301][301][302];
    for(int i=0; i<=N; i++) for(int j=0; j<=N; j++) for(int k=0; k<=K; k++) dp[i][j][k] = 1e18;
    dp[0][0][0] = 0;
    for(int i=0; i<N; i++) for(int j=0; j<=N; j++) for(int k=0; k<=K; k++){
        chmin(dp[i+1][i+1][k], dp[i][j][k] + max(0, H[i+1] - H[j]));
        chmin(dp[i+1][j][k+1], dp[i][j][k]);
    }
    int64_t ans = 1e18;
    for(int j=0; j<=N; j++) for(int k=0; k<=K; k++) chmin(ans, dp[N][j][k]);
    cout << ans << endl;
    return 0;
}
