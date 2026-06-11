#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P  = pair<int, int>;
int main() {
    int w, h, x, y;
    cin >> w >> h >> x >> y;
    cout << setprecision(15) << (double)w * h / 2.0 << " ";
    cout << (x && y && w / x / 2 * x * 2== w && h / y / 2 * y * 2 == h ? 1 : 0) << endl;
    return 0;
}