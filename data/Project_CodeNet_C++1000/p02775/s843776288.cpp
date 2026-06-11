#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    reverse(s.begin(), s.end());
    vector<vector<int> > dp(s.size() + 1, vector<int>(2, INF));
    dp[1][0] = s[0] - '0'; dp[1][1] = 11 - s[0] + '0';
    for (int i = 1 ; i < s.size() ; i++) {
        int cur = s[i] - '0';
        dp[i + 1][0] = min(dp[i][0], dp[i][1]) + cur;
        dp[i + 1][1] = min(dp[i][0] + 11 - cur, dp[i][1] + 10 - (cur + 1));
    }
    cout << min(dp.back()[0], dp.back()[1]) << '\n';
}