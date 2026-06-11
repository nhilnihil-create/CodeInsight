/**
 * File              : E-tutorial.cpp
 * Author            : JCHRYS <jchrys@me.com> Date              : 16.03.2020
 * Last Modified Date: 17.03.2020
 * Last Modified By  : JCHRYS <jchrys@me.com>
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string s;

int get(int idx) {
    return s[idx] - '0';
}


int main() {
    cin >> s;
    s = '0' + s;
    int n = s.size();
    vector<vector<ll>> dp(n, vector<ll>(2, 0));
    //dp[i][j] -> min # paper need at index j, i == 0 ? not carry: carry;
    dp[0][0] = 0;
    dp[0][1] = 1;
    for (int i = 1; i < n; ++i) {
        dp[i][0] = min(dp[i - 1][0] + get(i), dp[i - 1][1] + 10 - get(i)); 
        dp[i][1] = min(dp[i - 1][0] + (get(i) + 1), dp[i - 1][1] + 10 - (get(i) + 1));
    }
    cout << dp[n - 1][0];
    
    return 0;
}
