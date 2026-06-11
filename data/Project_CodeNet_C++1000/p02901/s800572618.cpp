#include <bits/stdc++.h>
using namespace std;

const int64_t INF = 1e+15;

int main() {
    int64_t N,M; // N 宝箱の個数　M 鍵の個数
    cin >> N >> M;
    
    vector<int64_t> a(M),b(M);
    vector<vector<int64_t>> c;
    c.assign(M,vector<int64_t>());
    for ( int64_t i = 0; i < M; ++i){
        cin >> a[i] >> b[i];
        for ( int64_t j = 0; j < b[i]; ++j){
            int64_t C;
            cin >> C;
            --C;
            c[i].push_back(C);
        }
    }
    
    vector<int64_t> f(M); // それぞれの鍵で開く宝箱
    for ( int64_t i = 0; i < M; ++i){
        int64_t F = 0;
        for ( int64_t j = 0; j < b[i]; ++j){
            int64_t C = c[i][j];
            F = F | (1<<C);
        }
        f[i] = F;
    }
    
    // すべての宝箱が開けられるかcheck
    int64_t open = 0;
    bool flg = true;
    for ( int64_t i = 0; i < M; ++i){
        open = open | f[i];
    }
    if ( open != (1<<N)-1 ){
        flg = false;
    }
    
    vector<int64_t> dp(1<<N);
    dp[0] = 0;
    for ( int i = 1; i < (1<<N); ++i){
        dp[i] = INF;
    }
    
    for ( int64_t i = 0; i < M; ++i){
        for ( int64_t k = 0; k < (1<<N); ++k){
            int64_t idx = k | f[i];
            dp[idx] = min(dp[idx],dp[k] + a[i]);
        }
    }
    
    
    
    
    
    
    
    if ( flg ) {
        cout << dp[(1<<N)-1] << endl;
    } else {
        cout << -1 << endl;
    }
    
    
    return 0;
}
