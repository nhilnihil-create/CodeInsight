#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e18;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> h(n+1);
    for(int i=1; i<=n; i++){
        cin >> h[i];
    }

    vector<vector<long long int>> dp(n-k+1, vector<long long int>(n+1, INF));
    // dp[i][j] = min #(operations) with i columns, the last column = j
    dp[0][0] = 0;
    for(int i=1; i<=n-k; i++){
        for(int j=1; j<=n; j++){
            for(int l=0; l<j; l++){
                dp[i][j] = min(dp[i][j], dp[i-1][l] + max(0, h[j] - h[l]));
            }
        }
    }
    
    long long int ans = INF;
    for(int j=0; j<=n; j++){
        ans = min(ans, dp[n-k][j]);
    }
    cout << ans << endl;
    return 0;
}