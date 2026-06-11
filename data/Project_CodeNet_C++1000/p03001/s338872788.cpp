#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    double W, H, x, y;
    cin >> W >> H >> x >> y;
    double ans = W * H / 2;
    bool multi = false;
    if (x == W / 2.0 && y == H / 2.0) {
        multi = true;
    }
    cout << fixed << setprecision(12) << ans << " " << multi << endl;
}
