#include <bits/stdc++.h>

#ifndef M_PI
#define M_PI 3.14159265358979
#endif
#define deg_to_rad(deg) (((deg) / 360) * 2 * M_PI)
#define rad_to_deg(rad) (((rad) / 2 / M_PI) * 360)

using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef long double ld;

const ll INF = 1e15;
const ll MOD = 1e9 + 7;

int main() {
    ll i, j, k;
    ld W, H, x, y;
    cin >> W >> H >> x >> y;
    cout << fixed << setprecision(2) << W * H / 2 << " ";
    if(x == W / 2 && y == H / 2) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
