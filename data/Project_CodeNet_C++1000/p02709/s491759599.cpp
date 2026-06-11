#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<long long int, int>> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    vector<vector<long long int>> dp(n+1, vector<long long int>(n+1));
    for(int i=0; i<n; i++){
        //cout << i << endl;
        for(int j=0; j<=i; j++){
            //cout << j << " : " << endl;
            dp[i+1][j]   = max(dp[i+1][j]  , dp[i][j] + a[i].first * (((n-1)-(i-j)) - a[i].second));
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + a[i].first * (a[i].second - j));
            //cout << "dp[" << i+1 << "][" << j << "] = " << dp[i+1][j] << endl;
            //cout << "dp[" << i+1 << "][" << j+1 << "] = " << dp[i+1][j+1] << endl;
        }
        //cout << endl;
    }
    long long int ans = 0;
    for(int i=0; i<=n; i++){
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}