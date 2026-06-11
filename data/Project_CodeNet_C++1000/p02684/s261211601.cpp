#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int up[70][n+1];
    for (int i = 1; i <= n; i++) {
        cin >> up[0][i];
    }
    for (int i = 1; i < 70; i++) {
        for (int node = 1; node <= n; node++) {
            up[i][node] = up[i-1][up[i-1][node]];
        }
    }
    int pow[70];
    pow[0] = 1;
    for (int i = 1; i < 70; i++) {
        pow[i] = pow[i-1]*2;
    }
    int u = 1;
    while (k != 0) {
        int log = 0;
        while (pow[log+1] < k) {
            log++;
        }
        u = up[log][u];
        k -= pow[log];
    }
    cout << u << endl;
}
/*

 */