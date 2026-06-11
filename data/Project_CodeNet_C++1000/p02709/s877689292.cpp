# include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;

int n;
long long dp[N][N];
pair <int, int> a[N];

int main() {
    cin >> n;

    for (int i = 1; i <= n;  i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++) {
        for (int l = 0; l < i; l++) {
            int r = (n + 1) - (i - l - 1);
            dp[l + 1][r] = max(dp[l + 1][r], dp[l][r] + abs(a[i].second - (l + 1)) *1ll* a[i].first);
            dp[l][r - 1] = max(dp[l][r - 1], dp[l][r] + abs(a[i].second - (r - 1)) *1ll* a[i].first);
        }
    }

    long long ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, dp[i][i + 1]);
    }

    cout << ans << endl;
}
