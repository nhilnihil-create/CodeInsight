#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<pair<int, int>> q(n);
    for (int i = 0; i < n; i++) {
        q[i] = {a[i], i};
    }
    sort(q.rbegin(), q.rend());

    vector<vector<long>> d(n + 1, vector<long>(n + 1, LLONG_MIN));
    d[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (d[i][j] == LLONG_MIN) continue;
            {
                //left
                d[i + 1][j + 1] = max(d[i + 1][j + 1],
                                      d[i][j] +
                                      (long) q[i].first * abs(q[i].second - j)
                );
            }
            {
                //right
                d[i + 1][j] = max(d[i + 1][j],
                                  d[i][j] +
                                  (long) q[i].first * abs(q[i].second - (n - 1 - (i - j)))
                );
            }
        }
    }
    long res = 0;
    for (int j = 0; j <= n; j++) {
        res = max(res, d[n][j]);
    }
    cout << res;

    return 0;
}