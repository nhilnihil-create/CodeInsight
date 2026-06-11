
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef long double ld;

#define INF (1e9)

int N;

int main() {
    cin >> N;

    vvd E(N, vd(2));
    double x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        E[i] = vd{x, y};
    }

    sort(E.begin(), E.end(), [](vd l, vd r) {
        return atan2(l[0], l[1]) < atan2(r[0], r[1]);
    });

    ld ans = 0;
    for (int l = 0; l < N; l++) {
        int r = l;
        ld sx = 0, sy = 0;
        do {
            sx += E[r][0];
            sy += E[r][1];
            ans = max(ans, sqrt(sx * sx + sy * sy));
            r++;
            r %= N;
        } while (l != r);
    }

    cout << setprecision(20) << ans << endl;
    return 0;
}
