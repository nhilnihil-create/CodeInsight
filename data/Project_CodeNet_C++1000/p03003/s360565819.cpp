#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i < n; i++)
#define rep3(i, x, n) for(int i = x; i > n; i--)
long long MOD = 1e9+7;
long long INF = 1e15;
typedef pair<long long, long long> P;

int main(){
    int N, M;
    cin >> N >> M;
    long long S[N+1], T[M+1];
    rep2(i, 1, N+1){
        cin >> S[i];
    }
    rep2(i, 1, M+1){
        cin >> T[i];
    }
    long long dp[N+1][M+1];
    rep(i, N+1){
        dp[i][0] = 1;
    }
    rep(i, M+1){
        dp[0][i] = 1;
    }
    rep2(i, 1, N+1){
        rep2(j, 1, M+1){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            if(S[i] != T[j]){
                dp[i][j] += MOD-dp[i-1][j-1];
            }
            dp[i][j] %= MOD;
        }
    }
    cout << dp[N][M] << endl;
}