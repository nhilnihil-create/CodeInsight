#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int k, q;
    cin >> k >> q;
    int d[k];
    for (int i = 0; i < k; ++i) cin >> d[i];
    while (q) {
        --q;
        int n, x, m;
        cin >> n >> x >> m;
        --n;
        int sum = 0, nols = 0;
        for (int j = 0; j < k; ++j) {
            sum += d[j] % m;
            if (d[j] % m == 0) ++nols;
        }
        x %= m;
        x += (n / k) * sum;
        nols *= (n / k);
        for (int j = 0; j < (n % k); ++j) {
            x += d[j] % m;
            if (d[j] % m == 0) ++nols;
        }
        cout << n - x / m - nols << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
