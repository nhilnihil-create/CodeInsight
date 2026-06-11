#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int dp[5005][5005];

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    rep(i, n) rep(j, n) {
        if (s[n-1-i]==s[n-1-j]) dp[n-1-i][n-1-j] = dp[n-i][n-j] + 1;
    }
    int ans = 0;
    rep(i, n) rep(j, n) {
        int tmp = min(dp[i][j], i-j);
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}