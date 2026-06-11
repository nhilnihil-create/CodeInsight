#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;
const int MAXN = 1e5 + 10;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(2));
    dp[0][1] = 1;
    for (int i = 0; i < n; i++) {
        int c = s[i] - '0';
        dp[i + 1][0] = min(dp[i][0] + c, dp[i][1] + 10 - c);
        dp[i + 1][1] = min(dp[i][0] + c + 1, dp[i][1] + 10 - c - 1);
    }
    cout << dp[n][0];
    return 0;
}
