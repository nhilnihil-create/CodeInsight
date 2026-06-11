#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

const int inf = 2e9;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int> > dp(n, vector<int>(m, inf));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + (a[i - 1][j] != a[i][j]));
            }
            if (j > 0) {
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + (a[i][j - 1] != a[i][j]));
            }
        }
    }

    int r = dp[n - 1][m - 1];
    if (a[0][0] == '#') r++;
    if (a[n - 1][m - 1] == '#') r++;
    cout << r / 2 << '\n';
}