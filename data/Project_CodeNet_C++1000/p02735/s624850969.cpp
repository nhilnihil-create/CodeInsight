#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> d(n, vector<int>(m));
    d[0][0] = a[0][0] == '#';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + j == 0) continue;
            d[i][j] = INT_MAX;
            if (i > 0) {
                int dd = d[i - 1][j];
                if (a[i][j] != a[i - 1][j]) dd++;
                d[i][j] = min(d[i][j], dd);
            }
            if (j > 0) {
                int dd = d[i][j - 1];
                if (a[i][j] != a[i][j - 1]) dd++;
                d[i][j] = min(d[i][j], dd);
            }
//            cout << i << " " << j << " " << d[i][j] << "\n";
        }
    }
    int res = d[n - 1][m - 1] + (a[n - 1][m - 1] == '#');
    cout << res / 2;

    return 0;
}