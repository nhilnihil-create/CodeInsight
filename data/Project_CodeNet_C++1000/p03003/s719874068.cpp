#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 1e9+7;
void add(int64_t& a, int64_t b){
    a = (a+b) % MOD;
}
void mul(int64_t& a, int64_t b){
    a = a*b % MOD;
}

int main(){
    int N, M, S[2000], T[2000];
    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> S[i];
    for(int i=0; i<M; i++) cin >> T[i];

    static int64_t dp[2001][2001];
    dp[0][0] = 1;
    for(int i=0; i<N; i++){
        int64_t sum = 0;
        for(int j=0; j<M; j++){
            add(sum, dp[i][j]);
            add(dp[i+1][j], dp[i][j]);
            if(T[j] == S[i]) add(dp[i+1][j+1], sum);
        }
        add(dp[i+1][M], dp[i][M]);
    }

    int64_t ans = 0;
    for(int j=0; j<=M; j++) add(ans, dp[N][j]);
    cout << ans << endl;
    return 0;
}
