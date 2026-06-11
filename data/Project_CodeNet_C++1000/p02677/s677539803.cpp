#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int a, b, h, m;
    cin >> a >> b >> h >> m;

    double ang1 = ((h + m / 60.0) / 12.0) * 2.0 * M_PI;
    double ang2 = (m / 60.0) * 2.0 * M_PI;
    if (ang1 < ang2) swap(ang1, ang2);
    double angdiff = ang1 - ang2;
    if (angdiff > M_PI) angdiff = 2 * M_PI - angdiff;

    double ans = sqrt(a * a + b * b - 2.0 * a * b * cos(angdiff));

    printf("%.15f\n", ans);

    return 0;
}
