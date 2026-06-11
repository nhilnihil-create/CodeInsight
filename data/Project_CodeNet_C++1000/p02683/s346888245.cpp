#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m >> x;

    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        cin >> c[i];
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int64_t ans = 123456789;
    for (int tmp = 1; tmp < (1 << n); tmp++) {
        bitset<12> s(tmp);
        // cout << s << endl;
        vector<int> skill(m, 0);
        int64_t sum = 0;
        for (int i = 0; i < n; i++) {
            if (s.test(i)) {
                sum += c[i];
                for (int j = 0; j < m; j++) {
                    skill[j] += a[i][j];
                }
            }
        }
        bool ok = true;
        for (int k = 0; k < m; k++) {
            if (skill[k] < x) {
                ok = false;
            }
        }
        if (ok) {
            ans = min(ans, sum);
        }
    }
    if (ans == 123456789) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}
