#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) for (int i=0;i<(n);++i)

using namespace std;

template <class T, class U> void amax(T& x, U y) {if (x < y) x = y;}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;

    int N = S.size();

    vector<vector<int>> dp(N + 1, vector<int>(2, -100));
    dp[0][0] = 0;
    dp[0][1] = 0;
    FOR(i, 1, N + 1) {
        FOR(c, 1, 2 + 1) {
            if (i - c < 0) continue;
            string T = S.substr(i - c, c);
            FOR(c0, 1, 2 + 1) {
                int i0 = max(i - c - c0, 0);
                string T0 = S.substr(i0, min(c0, i - c));
                if (T != T0) {
                    amax(dp[i][c - 1], dp[i - c][c0 - 1] + 1);
                }
            }
        }
    }

    int result = max(dp[N][0], dp[N][1]);

    cout << result << endl;

    return 0;
}
