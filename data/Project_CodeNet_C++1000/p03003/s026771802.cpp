#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 2e3 + 5, mod = 1e9 + 7;
int dp[N][N][3];
int a[N], b[N];

int n, m;

int solve(int i, int j, int s) {
    if (i == n || j == m) return s == 0;
    int &ret = dp[i][j][s];
    if (ret != -1) return ret;
    ret = 0;
    if (s == 0) {
        ret = 1 + solve(i + 1, j + 1, 1);
    }
    if (s == 1) {
        ret = solve(i + 1, j, 1);
        ret = (ret + solve(i, j, 2)) % mod;
    }
    if (s == 2) {
        ret = solve(i, j + 1, 2);
        if (a[i] == b[j]) {
            ret = (ret + solve(i, j, 0)) % mod;
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    cout << (solve(0, 0, 1) + 1) % mod << endl;
    return 0;
}