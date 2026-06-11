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
    ld A, B, H, M;
    cin >> A >> B >> H >> M;
    ld tm = 6 * M;
    ld th = 30 * H + 0.5 * M;
    ld t = abs(tm - th);
    t = min(t, 360 - t);
    t = deg_to_rad(t);
    cout << fixed << setprecision(15)
         << sqrt(A * A + B * B - 2 * A * B * cos(t)) << endl;

    return 0;
}
