//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("fma,avx,avx2")

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double
#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()
#define x first
#define y second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 2e3 + 10;
const int p = 1e9 + 7;

int a[maxn], b[maxn];
int dp[maxn][maxn], sum[maxn][maxn];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    for (int i = 0; i <= m; i++) {
        sum[0][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            sum[i][j] = sum[i - 1][j] + (j == 0 ? 0 : sum[i][j - 1]) - (j == 0 ? 0 : sum[i - 1][j - 1]);
            if (a[i] == b[j]) sum[i][j] = (sum[i][j] + (j == 0 ? 0 : sum[i - 1][j - 1]) + p) % p;
            sum[i][j] = (sum[i][j] + p) % p;
        }
    }
    cout << sum[n][m] << "\n";

    return 0;
}
