#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359;
#define inf (1 << 21);
#define mod 1000000007;

int main() {
    double W, H; cin >> W >> H;
    double x, y; cin >> x >> y;
    cout << fixed << setprecision(10);
    if (x == W / 2 && y == H / 2) {
        cout << W * H / 2 << ' ' << 1 << endl;
    }
    else {
        cout << W * H / 2 << ' ' << 0 << endl;
    }
    return 0;
}