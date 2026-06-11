#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
const int MN = 1e5 + 5, LN = 17, MOD = 1e9 + 7, INF = 0x3f3f3f3f;
int N, M, dp[(1 << 12) + 2];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    cin >> N >> M;
    int mn = 1e9;
    for (int i = 1; i <= M; i++) {
        int a, b, mask = 0;
        cin >> a >> b;
        for (int j = 0; j < b; j++) {
            int c; cin >> c;
            mask |= 1 << (c - 1);
        }
        for (int cur = (1 << N) - 1; cur >= 0; cur--) {
            if (dp[cur] == INF) continue;
            int nxt = cur | mask;
            dp[nxt] = min(dp[nxt], dp[cur] + a);
        }
        mn = min(mn, dp[(1 << N) - 1]);
    }
    if (mn == 1e9) mn = -1;
    cout << mn << '\n';
    return 0;
}
