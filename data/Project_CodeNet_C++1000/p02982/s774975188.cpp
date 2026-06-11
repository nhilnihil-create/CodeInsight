#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
int n, d, x[11][11], p, q, res;
int main() {
    DAU
    cin >> n >> d;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= d; ++j)
            cin >> x[i][j];
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j) {
            p = 0;
            for (int k = 1; k <= d; ++k)
                p += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
            q = sqrt(p);
            res += (q * q == p);
        }
    cout << res;
    PLEC
}
