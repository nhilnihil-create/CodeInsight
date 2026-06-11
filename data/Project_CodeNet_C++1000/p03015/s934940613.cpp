#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;
const int MAX = 100010;

lint dp[MAX][2];

int main() {
    string s;
    cin >> s;
    int n = s.size();

    dp[0][0] = 1;

    rep(i, n) {
        int ni = i+1;
        int nd = s[i] - '0';
        rep(j, 2) {
            if (j) {
                dp[ni][j] += dp[i][j] * 3;
                dp[ni][j] %= MOD;
            }
            else {
                if (nd == 1) {
                    dp[ni][0] += dp[i][j] * 2;
                    dp[ni][0] %= MOD;
                    dp[ni][1] += dp[i][j];
                    dp[ni][1] %= MOD;
                }
                else {
                    dp[ni][j] += dp[i][j];
                    dp[ni][j] %= MOD;
                }
            }
        }
    }
    
    lint res = dp[n][0] + dp[n][1];
    res %= MOD;

    cout << res << endl;
    return 0;
}