#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    string S; cin >> S;
    int N = S.size();

    int dp[N + 1][2] = {};
    dp[0][1] = 1;
    REP(i, 0, N) {
        int n = S[i] - '0';
        dp[i + 1][0] = min(dp[i][0] + n, dp[i][1] + (10 - n));
        dp[i + 1][1] = min(dp[i][0] + n + 1, dp[i][1] + (10 - n - 1));
    }

    cout << dp[N][0] << endl;
    return 0;
}