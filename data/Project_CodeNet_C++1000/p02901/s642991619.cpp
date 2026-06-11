#include <bits/stdc++.h>
using namespace std;
const int M = 1e3 + 5;
const int N = (1 << 12) + 5;
int dp[M][N];
int n, m;
int cost[M];
vector<int> boxes[M];
int solve(int idx, int msk) {
    if ((1 << n) - 1 == msk) return 0;
    if (idx == m) return 1e9;
    int &ret = dp[idx][msk];
    if (ret != -1) return ret;
    ret = solve(idx + 1, msk);
    for (auto curr: boxes[idx]) {
        msk |= (1 << curr);
    }
    ret = min(ret, solve(idx + 1, msk) + cost[idx]);
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cost[i] = a;
        for (int j = 0; j < b; j++) {
            int x;
            cin >> x;
            boxes[i].push_back(x - 1);
        }
    }
    memset(dp, -1, sizeof dp);
    if (solve(0, 0) >= 1e9) cout << -1;
    else cout << solve(0, 0);
    return 0;
}