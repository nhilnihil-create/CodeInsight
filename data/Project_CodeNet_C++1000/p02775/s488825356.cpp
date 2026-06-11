#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

int dp[1000100][2];

int main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    s += "0";
    int n = s.size();
    rep(i, n + 1) {
        rep(j, 2) {
            dp[i][j] = 1e9;
        }
    }
    dp[0][0] = 0;
    rep(i, n) {
        rep(j, 2) {
            int x = s[i] - '0';
            x += j;
            rep(a, 10) {
                int nj = 0;
                int b = a - x;
                if (b < 0) {
                    nj = 1;
                    b += 10;
                }
                dp[i + 1][nj] = min(dp[i + 1][nj], dp[i][j] + (int)a + b);
            }
        }
    }
    cout << dp[n][0] << endl;
}
