#include <bits/stdc++.h>
#define reo(i,n) for (int i = 0; i < int(n); i++)
using namespace std;
using ll = long long;

string s;
ll dp[1100100][2];

int main() {
    cin >> s;
    dp[0][1] = 1;
    for (int i = 0; i < (int) s.length(); i++) {
        int num = (int)(s[i] - '0');
        dp[i+1][0] = min(dp[i][0] + num, dp[i][1] + (10 - num));
        dp[i+1][1] = min(dp[i][0] + num + 1, dp[i][1] + (10 - num - 1));
    }
    cout << dp[(int)s.length()][0] << endl;
    return 0;
}