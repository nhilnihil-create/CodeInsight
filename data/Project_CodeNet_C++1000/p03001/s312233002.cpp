#include <bits/stdc++.h>
using namespace std;

int main() {
    int W, H, x, y;
    cin >> W >> H >> x >> y;
    double ans = (double)W * H / 2;
    cout << fixed << setprecision(15);
    cout << ans << " " << (x * 2 == W && y * 2 == H) << endl;
}