#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    int dp[n + 3][2];
    dp[0][0] = 0, dp[0][1] = 1;
    for(int i = 0; i < s.size(); i++){
        int d = s[i] - '0';
        dp[i + 1][0] = min(dp[i][0] + d, dp[i][1] + 10 - d);
        dp[i + 1][1] = min(dp[i][0] + d + 1, dp[i][1] + 10 - d - 1);
    }
    cout << dp[n][0];
    return 0;
}