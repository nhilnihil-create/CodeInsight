#include<bits/stdc++.h>

using namespace std;

int a[105][105];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, d, ans = 0;
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= d; ++j) cin >> a[i][j];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int s = 0;
            for (int w = 1; w <= d; ++w) s += (a[i][w] - a[j][w]) * (a[i][w] - a[j][w]);
            int f = sqrtl(s);
            for (int d = max(0, f - 1); d <= f + 1; ++d) {
                if (d * d == s) ans++;
            }
        }
    }
    cout << ans;
    return 0;
}

