#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 107;
signed main() {
    cout.precision(20);
    double W, H, x, y;
    cin >> W >> H >> x >> y;
    double sq = (W * H) / 2.0;
    cout << fixed << sq << " ";
    if (2 * x == W & 2 * y == H) cout << 1 << ' ';
    else cout << 0 << '\n';
}