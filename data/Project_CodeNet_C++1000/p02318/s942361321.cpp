#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    vector<vector<int> > dp(s.size() + 1, vector<int>(t.size() + 1, 100000));
    dp[0][0] = 0;
    for (int i = 0; i <= s.size(); i++) dp[i][0] = i;
    for (int j = 0; j <= t.size(); j++) dp[0][j] = j;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < t.size(); j++) {
            int cnt = 1;
            if (s[i] == t[j]) cnt = 0;
            dp[i + 1][j + 1] =
                min({dp[i][j + 1] + 1, dp[i + 1][j] + 1, dp[i][j] + cnt});
        }
    }
    cout << dp[s.size()][t.size()] << endl;
}
