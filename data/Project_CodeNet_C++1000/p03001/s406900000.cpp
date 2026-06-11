#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    double W, H, x, y;
    cin >> W >> H >> x >> y;

    cout << fixed << setprecision(20) << W * H / 2 << ' ';
    cout << int(2 * x == W && 2 * y == H) << endl;

    return 0;
}