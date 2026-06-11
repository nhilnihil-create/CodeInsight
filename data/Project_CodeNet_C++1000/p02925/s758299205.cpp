#include <bits/stdc++.h>
using ll = long long;
using namespace std;

constexpr int inf = 1e9;
constexpr ll linf = 1e18;

int id[1001][1001];
vector<int> g[1001 * 1001];
int dp[1001 * 1001];
bool calc[1001 * 1001];

inline int get_id(int i, int j)
{
    if (i > j) swap(i, j);
    return id[i][j];
}

int dfs(int u)
{
    if (dp[u] != -1) return calc[u] ? dp[u] : -1;
    dp[u] = 1;
    for (auto &v: g[u]) {
        int res = dfs(v);
        if (res == -1) return -1;
        dp[u] = max(dp[u], res + 1);
    }
    calc[u] = true;
    return dp[u];
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n - 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }

    int v = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) id[i][j] = v++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 2; j++) {
            int from = get_id(i, a[i][j]);
            int to   = get_id(i, a[i][j + 1]);
            g[from].push_back(to);
        }
    }

    memset(dp, 0xff, sizeof(dp));

    int ans = 0;
    for (int i = 0; i < v; i++) {
        int res = dfs(i);
        if (res == -1) {
            cout << -1 << endl;
            return 0;
        }

        ans = max(ans, res);
    }
    cout << ans << endl;
    return 0;
}