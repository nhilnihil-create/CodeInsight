#include <bits/stdc++.h>
using namespace std;

int dp[1000002][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 1000002; j++) {
            dp[j][i] = 1e9;
        }
    }
    dp[0][0] = 0;
    dp[0][1] = 1;

    int n = s.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            int a = s[i] - '0';
            if (j == 1) a++;
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + a);
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][j] + 10 - a);
        }
    }

    cout << min(dp[n][0], dp[n][1] + 1) << endl;
}
