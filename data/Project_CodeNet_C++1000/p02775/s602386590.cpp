#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n+1, vector<int>(2, 0));
    dp[0][1] = 1;
    for(int i = 1; i <= n; i++){
        dp[i][0] = min(dp[i-1][0] + (s[i-1]-'0'), dp[i-1][1] + 10 - (s[i-1]-'0'));
        dp[i][1] = min(dp[i-1][0] + (s[i-1]-'0') + 1, dp[i-1][1] + 10 - (s[i-1]-'0') - 1);
    }
    cout << dp[n][0] << endl;
}