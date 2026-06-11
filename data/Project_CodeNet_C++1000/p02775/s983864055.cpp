#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    string s;
    cin >> s;
    int sum = 0;
    
    int dp[s.size() + 1][2];
    dp[0][0] = 0;
    dp[0][1] = 1;
    for (int i = 1; i <= s.size(); i ++) {
        dp[i][0] = min(dp[i - 1][0] + s[i - 1] - '0',       dp[i - 1][1] + 10 - s[i - 1] + '0');
        dp[i][1] = min(dp[i - 1][0] + s[i - 1] - '0' + 1,   dp[i - 1][1] + 9 - s[i - 1] + '0');
   }

    cout << dp[s.size() ][0];
    return 0;

}