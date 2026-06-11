#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (a); i > (b); i--)
#define ALL(a) (a).begin(), (a).end()
const int MOD = 998244353;

int main() {
    ll N, S;
    cin >> N >> S;
    ll A[N];
    REP(i, N) cin >> A[i];

    ll dp[N + 1][S + 1] = {};
    dp[0][0] = 1;
    REP(i, N) REP(j, S + 1) {
        dp[i + 1][j] += 2 * dp[i][j];
        dp[i + 1][j] %= MOD;

        ll sum = j + A[i];
        if (sum > S) continue;
        dp[i + 1][sum] += dp[i][j];
        dp[i + 1][sum] %= MOD;
    }
    cout << dp[N][S] << endl;
    return 0;
}