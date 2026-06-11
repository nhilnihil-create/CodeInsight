#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int n, m, x; cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }    
    int ans = 100000000;
    for (int bit = 0; bit < (1 << n); ++bit) {
        int tmpAns = 0;
        vector<int> tmpPoint(m, 0);
        for (int i = 0; i < n; ++i) {
            if (bit & (1 << i)) {
                tmpAns += c[i];
                for (int j = 0; j < m; j++) {
                    tmpPoint[j] += a[i][j];
                }
            }
        }
        bool ok = true;
        for (int j = 0; j < m; j++) {
            if (tmpPoint[j] < x) ok = false;
        }
        if (ok) ans = min(ans, tmpAns);
    }
    if (ans == 100000000) ans = -1;
    cout << ans << endl;
    return 0;
}