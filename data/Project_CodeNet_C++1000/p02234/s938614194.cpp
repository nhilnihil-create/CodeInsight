#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)


const int INF = 1e9;
int main() {
    int n;
    cin >> n;
    vector<int> p(n+1);
    int dp[105][105];
    rep(i,n) cin >> p[i] >> p[i+1];
    rep(i,n){
        rep(j,n) dp[i][j] = INF;
    }
    int mn;
    for(int i = 0; i < n; ++i) dp[i][i] = 0;
    for(int l = 2; l <= n; ++l){
        for(int i = 1; i + l -1 <= n; ++i){
            int j = i + l -1;
            for(int k = i; k < j; ++k){
                if(k==i) mn = dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j];
                else mn = min(mn, dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j]);
            }
            dp[i][j] = mn;
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}
