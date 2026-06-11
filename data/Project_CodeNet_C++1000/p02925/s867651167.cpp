#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int n;
const int MAXN = 1e3 + 1;
const int MAXV = 1e6 + 1;
int id[MAXN][MAXN];
vector<int> to[MAXV];

vector<int> reached_loop(MAXV, -1);
bool looped(int v) {
    if (reached_loop[v] >= 0) {
        return reached_loop[v] > 0;
    }
    reached_loop[v] = 1;
    int ret = 0;
    for (int next: to[v]) {
        if (looped(next)) {
            ret = 1;
            break;
        }
    }
    reached_loop[v] = ret;
    return ret > 0;
}

vector<bool> reached(MAXV, false);
vector<int> dp(MAXV, 0);
int dfs(int v) {
    if (reached[v]) {
        return dp[v];
    }
    reached[v] = true;
    dp[v] = 1;
    for (int e: to[v]) {
        dp[v] = max(dp[v], dfs(e) + 1);
    }
    return dp[v];
}

int main() {
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n - 1));
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n - 1; k++) {
            cin >> a[i][k];
            a[i][k]--;
        }
    }
    int v = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int k = 1; k < n; k++) {
            id[i][k] = v;
            v++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int k = 1; k < n - 1; k++) {
            to[id[min(i, a[i][k - 1])][max(i, a[i][k - 1])]].emplace_back(id[min(i, a[i][k])][max(i, a[i][k])]);
        }
    }
    int ans = 0;
    for (int i = 0; i < v; i++) {
        if (looped(i)) {
            cout << -1 << endl;
            return 0;
        }
        ans = max(ans, dfs(i));
    }
    cout << ans << endl;
    return 0;
}

