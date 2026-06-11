#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
queue<pair<int, int>> q;
int n, m, x, kk, k, y, start, stop, res;
int main() {
    DAU
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    while (m--) {
        cin >> x >> y;
        g[x].emplace_back(y);
    }
    cin >> start >> stop;
    q.emplace(start, 0);
    vector<vector<int>> dp(n + 1, vector<int>(3, -1));
    dp[start][0] = 0;
    while (!q.empty()) {
        tie(x, kk) = q.front();
        q.pop();
        k = (kk + 1) % 3;
        for (const int& y : g[x])
            if (dp[y][k] == -1 || dp[x][kk] + 1 < dp[y][k]) {
                dp[y][k] = dp[x][kk] + 1;
                q.emplace(y, k);
            }
    }
    res = dp[stop][0];
    if (res != -1)
        res /= 3;
    cout << res;
    PLEC
}
