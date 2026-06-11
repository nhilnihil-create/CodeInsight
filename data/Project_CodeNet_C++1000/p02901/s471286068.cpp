#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    long long INF = 1e9;
    vector<int> c(M, 0);
    vector<int> a(M);
    for(int i = 0; i < M; i++){
        int d;
        cin >> a[i] >> d;
        for(int j = 0; j < d; j++){
            int e;
            cin >> e;
            e--;
            c[i] += (1 << e);
        }
    }
    vector<vector<long long>> dp(M + 1, vector<long long> ((1 << N), INF));
    dp[0][0] = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < (1 << N); j++){
            dp[i + 1][j] = min(dp[i][j], dp[i + 1][j]);
            if(dp[i][j] != INF) dp[i + 1][j | c[i]] = min(dp[i + 1][j | c[i]], dp[i][j] + a[i]);
        }
    }
    if(dp[M][(1 << N) - 1] == INF) cout << -1 << endl;
    else cout << dp[M][(1 << N) - 1] << endl;
}