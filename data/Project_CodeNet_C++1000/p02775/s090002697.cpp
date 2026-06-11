#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize(2)
#pragma G++ optimize(2)

#include <bits/stdc++.h>

#define LL long long
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pll pair<LL, LL>
#define pdd pair<double, double>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define length(p1, p2) ((p1.fi-p2.fi)*(p1.fi-p2.fi)+(p1.se-p2.se)*(p1.se-p2.se))
#define ith(state, i) (state & (1 << i))
#define PI acos(-1.0)
#define SZ(x) ((int)(x.size()))

using namespace std;

constexpr int N = 1e6+9;
constexpr int M = 1e9+9;
constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int INF2 = 0xcfcfcfcfcfcfcfcf;

string pay;
int dp[N][2];

int solve(int i, int f) {
    if (i < 0) return f ? INF : 0;
    int& ans = dp[i][f];
    if (ans != INF) return ans;
    int n = pay[i] - '0';
    if (f) {
        ans = min(ans, 10 - n + solve(i-1, 0));
        ans = min(ans, 10 - n - 1 + solve(i-1, 1));
    } else {
        ans = min(ans, n + solve(i-1, 0));
        ans = min(ans, n + 1 + solve(i-1, 1));
    }
    return ans;
}

signed main() {
    fastio;
    cin >> pay;
    memset(dp, 0x3f, sizeof(dp));
    reverse(pay.begin(), pay.end());
    cout << min(1 + solve(SZ(pay)-1, 1), 0 + solve(SZ(pay)-1, 0)) << endl;
    return 0;
}