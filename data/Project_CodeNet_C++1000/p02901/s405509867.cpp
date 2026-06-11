#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dp[1005][1 << 15];
signed main() {
    int N,M;
    cin >> N >> M;
    for(int i = 0; i < 1005; i++) {
        for(int j = 0; j < (1 << 15); j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for(int i = 0; i < M; i++) {
        int a,b;
        cin >> a >> b;
        vector<int>c(N);
        for(int i = 0; i < b; i++) {
            int C;
            cin >> C;
            C--;
            c[C] = 1;
        }
        for(int j = 0; j < (1 << N); j++) {
            dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
            int X = j;
            for(int k = 0; k < N; k++) {
                if(c[k] && !(1 & (j >> k))) {
                    X ^= 1 << k;
                }
            }
            dp[i+1][X] = min(dp[i+1][X],dp[i][j]+a);
        }
    }
    if(dp[M][(1 << N)-1] == INF) {
        cout << -1 << endl;
        return 0;
    }
    cout << dp[M][(1 << N)-1] << endl;
}
