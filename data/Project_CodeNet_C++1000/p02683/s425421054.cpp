#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, m, x; cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        for (auto &e : a[i]) cin >> e;
    }

    int cost = INT_MAX;
    for (int i = 1; i < (1 << n); ++i) {
        int csum = 0;
        vector<int> asum(m, 0);

        for (int j = 0; j < n; ++j) {
            if (!(i & (1 << j))) continue;
            csum += c[j];
            for (int k = 0; k < m; ++k) {
                asum[k] += a[j][k];
            }
        }

        bool bad = false;
        for (auto e : asum) {
            if (e < x) {
                bad = true;
                break;
            }
        }
        if (bad) continue;

        cost = min(cost, csum);
    }

    if (cost == INT_MAX) {
        cout << -1 << endl;
    }
    else {
        cout << cost << endl;
    }
}

