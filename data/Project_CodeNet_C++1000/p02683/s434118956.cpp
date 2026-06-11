#include<iostream>
using namespace std;

int main() {
    int n, m, x;
    int a[20][20], c[20];

    cin >> n >> m >> x;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }

    int ans = 1<<30;
    int all = 1<<n;
    for (int mask = 0; mask < all; mask++) {
        int level[20] = {};
        int cost = 0;
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                cost += c[i];
                for (int j = 0; j < m; j++) level[j] += a[i][j];
            }
        }

        bool master = true;
        for (int i = 0; i < m; i++) {
            if (level[i] < x) master = false;
        }

        if (master) ans = min(ans, cost);
    }

    if (ans == 1 << 30) cout << -1 << endl;
    else cout << ans << endl;
}