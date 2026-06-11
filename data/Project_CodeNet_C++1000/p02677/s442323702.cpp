#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
    int a, b, h, m;
    double ang, c;
    cin >> a >> b >> h >> m;
    ang = abs((6 * m) - (30 * h + 0.5 * m));
    c = a * a + b * b - 2 * a * b * cos(ang / 180.0 * M_PI);
    printf("%.20lf\n",sqrt(c));
    return 0;
}