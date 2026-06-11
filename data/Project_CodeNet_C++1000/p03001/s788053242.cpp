#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

double w, h, x, y;
int main() {
    cin >> w >> h >> x >> y;
    cout << w * h / 2 << ' ' << ((x == w / 2 && y == h / 2) ? 1 : 0) << endl;
    return 0;
}
