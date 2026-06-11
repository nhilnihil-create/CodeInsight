#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <cmath>
#include <cstdio>

using namespace std;

typedef long long ll;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)

#define MOD 1000000007

int main(int argc, char **argv)
{
    string S;
    cin >> S;

    int N = S.length();
    ll dp[N + 1][13];

    REP(i, N + 1) REP(j, 13) dp[i][j] = 0;
    dp[0][0] = 1;

    REP(i, N) {
        int c;
        if (S[i] == '?') c = -1;
        else c = S[i] - '0';

        REP(j, 13) {
            if (c == -1) {
                REP(k, 10) {
                    dp[i + 1][((10 * j) + k) % 13] += dp[i][j];
                }
            }
            else {
                dp[i + 1][((10 * j) + c) % 13] += dp[i][j];
            }
        }
        REP(j, 13) dp[i + 1][j] = dp[i + 1][j] % MOD;
    }

    cout << dp[N][5] << endl;


    return 0;
}
