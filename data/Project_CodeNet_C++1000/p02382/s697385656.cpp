#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

int
main(int argc, const char *argv[])
{
    int n;
    vector<int> vx, vy;
    cin >> n;
    for (int i = 0; i < n; ++i) { int x; cin >> x; vx.push_back(x); }
    for (int i = 0; i < n; ++i) { int y; cin >> y; vy.push_back(y); }
    double r1 = 0, r2 = 0, r3 = 0, r4 = 0;
    for (int i = 0; i < vx.size(); ++i) {
        double abs_r = abs(vx[i] - vy[i]);
        r1 += abs_r;
        r2 += abs_r * abs_r;
        r3 += abs_r * abs_r * abs_r;
        r4 = r4 > abs_r ? r4 : abs_r;
    }
    printf("%.6lf\n%.6lf\n%.6lf\n%.6lf\n", r1, sqrt(r2), pow(r3, 1.0/3), r4);

    return 0;
}