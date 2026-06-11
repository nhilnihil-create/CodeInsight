#include <bits/stdc++.h>
#define int long long
#pragma GCC optimize("O3,Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,sse")
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int w, h, x, y;
    cin >> w >> h >> x >> y;
    double opt = w * h / 2.0;
    if (x * 2 == w && y * 2 == h) {
        cout << opt << ' ' << 1 << '\n';
    } else {
        cout << opt << ' ' << 0 << '\n';
    }

    fflush(stdout);
    return 0;
}
