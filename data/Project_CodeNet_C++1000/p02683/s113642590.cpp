#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, m, k, c[17] = {}, a[17][17] = {}, z = mod;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }
    for (int i = 0; i < (1 << n); i++) {
        int d[17] = {}, e = 0, y = 0;
        for (int j = 0; j < n; j++) if (i & (1 << j)) {
            e += c[j];
            for (int l = 0; l < m; l++) d[l] += a[j][l];
        }
        for (int j = 0; j < m; j++) if (d[j] < k) y = 1;
        if (!y) z = min(z, e);
    }
    if (z == mod) cout << -1;
    else cout << z;
}
