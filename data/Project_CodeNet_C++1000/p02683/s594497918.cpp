#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

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
    int ans = INT_MAX;
    for (int tmp = 0; tmp < (1 << n); tmp++) {
        bitset<12> comb(tmp);
        vector<int> app(m, 0);
        int price = 0;
        for (int i = 0; i < n; i++) {
            if (comb.test(i)) {
                price += c[i];
                for (int j = 0; j < m; j++) {
                    app[j] += a[i][j];
                }
            }
        }
        bool flag = true;
        for (int j = 0; j < m; j++) {
            if (app[j] < x) flag = false;
        }
        if (flag) ans = min(ans, price);
    }
    if (ans == INT_MAX) ans = -1;
    cout << ans << endl;
    return 0;
}