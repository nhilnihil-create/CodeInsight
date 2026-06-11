#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    pair<long long, long long>v[n + 3];
    for(long long i = 1; i <= n; i++){
        long long x;
        cin >> x;
        v[i] = {x, i};
    }
    sort(v + 1, v + n + 1, greater<pair<long long, long long> >());
    long long dp[n + 3][n + 3];
    dp[1][0] = v[1].first * abs(v[1].second - n);
    dp[1][1] = v[1].first * abs(v[1].second - 1);
    for(int i = 2; i <= n; i++){
        dp[i][0] = dp[i - 1][0] + v[i].first * abs(v[i].second - (n - i + 1));
        dp[i][i] = dp[i - 1][i - 1] + v[i].first * abs(v[i].second - i);
        for(int j = 1; j < i; j++){
            dp[i][j] = max(dp[i - 1][j] + v[i].first * abs(v[i].second - (n - i + j + 1)), dp[i - 1][j - 1] + v[i].first * abs(v[i].second - j));
        }
    }
    long long ans = 0;
    for(int i = 0; i <= n; i++){
        ans = max(ans, dp[n][i]);
    }
    cout << ans;
    return 0;
}