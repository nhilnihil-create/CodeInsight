#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;
const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(13));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 13; j++) {
            if (s[i] != '?') {
                dp[i + 1][(10 * j + s[i] - '0') % 13] += dp[i][j];
                if (dp[i + 1][(10 * j + s[i] - '0') % 13] >= mod) dp[i + 1][(10 * j + s[i] - '0') % 13] -= mod;
            } else {
                for (int l = 0; l < 10; l++) {
                    dp[i + 1][(10 * j + l) % 13] += dp[i][j];
                    if (dp[i + 1][(10 * j + l) % 13] >= mod) dp[i + 1][(10 * j + l) % 13] -= mod;
                }
            }
        }
    }
    cout << dp[n][5];
    return 0;
}
