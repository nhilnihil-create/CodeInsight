// 解説AC
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define int long long

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);     // a[d]: 深さdの葉の数
    vector<int> b(n + 1, 0);  // b[d]: 深さdの葉以外の頂点数
    for (int i = 0; i < n + 1; i++) cin >> a[i];

    vector<int> csa(n + 1 + 1);  // csa[i+1]-csa[j]: a[j]からa[i]までの和
    csa[0] = 0;
    for (int i = 0; i < n + 1; i++) csa[i + 1] = csa[i] + a[i];

    for (int d = 0; d <= n; d++) {
        if (d == 0) {
            b[d] = 1 - a[d];
            continue;
        }

        const int bmin = b[d - 1] - a[d];
        const int bmax = min(2 * b[d - 1] - a[d], csa[n + 1] - csa[d + 1]);

        b[d] = bmax;
    }

    int ans = 0;
    bool cant = false;  // 構築できない

    for (auto &&i : a) {
        ans += i;
    }
    for (auto &&i : b) {
        if (i < 0) cant |= true;
        ans += i;
    }

    if (cant)
        cout << -1 << endl;
    else
        cout << ans << endl;
}
