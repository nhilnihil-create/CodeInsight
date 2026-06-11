#include <bits/stdc++.h>
using namespace std;
int main(){
    string N;
    cin >> N;
    long long n = N.size();
    long long dp[n][2];
    dp[0][0] = N[n - 1] - '0';
    dp[0][1] = 10 - (N[n - 1] - '0') + 1;
    for(int i = 1; i < N.size(); i++){
        dp[i][0] = min(dp[i - 1][0] + N[n - 1 - i] - '0', dp[i - 1][1] + N[n - 1 - i] - '0');
        dp[i][1] = min(dp[i - 1][0] + 10 - (N[n - 1 - i] - '0') + 1, dp[i - 1][1] + 9 - (N[n - 1 - i] - '0'));
    }
    long long ans = min(dp[n - 1][0], dp[n - 1][1]);
    cout << ans << endl;
}