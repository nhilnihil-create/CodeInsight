#include <bits/stdc++.h>

using namespace std;

const int N = 13;
const int M = 1e3 + 1;

int c[M], keys[M];
int dp[M][1 << N];
int n, m, k;

int solve(int i, int mask) {
    if (i == m) {
        if (mask == (1 << n) - 1) {
            return 0;
        }
        return 1e9;
    }
    int& ans = dp[i][mask];
    if (ans != -1) {
        return ans;
    }
    ans = min(solve(i + 1, mask), solve(i + 1, mask | keys[i]) + c[i]);
    return ans;

}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> c[i] >> k;
        while (k--) {
            int key;
            cin >> key;
            keys[i] |= (1 << (key - 1));
        }
    }
    memset(dp, -1, sizeof dp);
    int ans = solve(0, 0);
    if (ans >= 1e9) {
        cout << -1;
    } else {
        cout << ans;
    }
    return 0;
}
