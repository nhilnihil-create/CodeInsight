#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    vector<vector<long>> d(n, vector<long>(n));
    // d[i][j] - закончили в i ст, взяли j ст

    long res = LONG_MAX;
    if (k == n) {
        res = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                d[i][j] = h[i];
            } else {
                d[i][j] = LONG_MAX;
                for (int t = 0; t < i; t++) {
                    if (j - 1 > t) continue;
                    long dd = d[t][j - 1];
                    if (h[i] > h[t]) {
                        dd += h[i] - h[t];
                    }
                    d[i][j] = min(d[i][j], dd);
                }
                if (j + 1 == n - k) {
                    res = min(res, d[i][j]);
                }
            }
//            cout << i << " " << j << " " << d[i][j] << "\n";
        }
    }
    cout << res;

    return 0;
}