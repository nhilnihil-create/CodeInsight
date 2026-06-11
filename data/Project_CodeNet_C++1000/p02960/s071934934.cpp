#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (int)(b); ++i)
#define FORR(i, a, b) for (int i = (a); i >= (int)(b); --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
typedef vector<P> VP;
typedef vector<PL> VPL;
typedef vector<string> VS;

const int MOD = (int)1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    reverse(ALL(s));
    int n = s.size();
    VVL dp(n + 1, VL(13, 0));
    VL pow10(n);
    pow10[0] = 1;
    FOR(i, 1, n - 1) pow10[i] = pow10[i - 1] * 10 % 13;
    dp[0][0] = 1;

    FOR(i, 1, n) FOR(m, 0, 12) {
        if (s[i - 1] == '?') {
            FOR(x, 0, 9) {
                dp[i][(pow10[i - 1] * x % 13 + m) % 13] =
                    (dp[i][(pow10[i - 1] * x % 13 + m) % 13] + dp[i - 1][m]) %
                    MOD;
            }
        } else {
            int x = s[i - 1] - '0';
            dp[i][(pow10[i - 1] * x % 13 + m) % 13] = dp[i - 1][m];
        }
    }

    cout << dp[n][5] << ln;
    return 0;
}
