#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, T;
    cin >> N >> T;
    vector<pair<int64_t,int64_t>> AB(N);
    for ( int64_t i = 0; i < N; ++i){
        int64_t p,q;
        cin >> p >> q;
        AB[i] = make_pair(p,q);
    }
    
    sort(AB.begin(),AB.end());
    
    /*for ( auto p: AB){
        cout << p.first << " " << p.second << endl;
    }*/
    
    vector<vector<int64_t>> dp(N,vector<int64_t>(T,0));
    
    for ( int64_t t = 0; t < T; ++t){
        int64_t A = AB[0].first;
        int64_t B = AB[0].second;
        if ( t < A ) dp[0][t] = 0;
        else dp[0][t] = B;
    }
    
    for ( int64_t i = 1; i < N; ++i){
        int64_t A = AB[i].first;
        int64_t B = AB[i].second;
        for ( int64_t t = 0; t < T; ++t){
            if ( t - A >= 0 ) dp[i][t] = max(dp[i-1][t],dp[i-1][t-A]+B);
            else dp[i][t] = dp[i-1][t];
        }
    }
    
    //int64_t ans_max = dp[0][T];
    int64_t ans_max = 0;
    for ( int64_t i = 1; i < N; ++i){
        int64_t A = AB[i].first;
        int64_t B = AB[i].second;
        int64_t ans = dp[i-1][T-1] + B;
        ans_max = max(ans_max,ans);
    }
    
    cout << ans_max << endl;
    
    return 0;
}