#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }

    bool yn = false;
    int ans = INT_MAX;
    for (int b = 1; b < (1<<n); b++) {
        int p = 0;
        vector<int> q(m, 0);
        for (int i = 0; i < n; i++) {
            if (b & (1<<i)) {
                p += c[i];
                for (int j = 0; j < m; j++) {
                    q[j] += a[i][j];
                }
            }
        }
        bool f = true;
        for (int i = 0; i < m; i++) {
            if (q[i] < x) f = false;
        }
        if (f) {
            yn = true;
            ans = min (ans, p);
        }
    }
    if (yn) cout << ans << endl;
    else cout << -1 << endl;
}