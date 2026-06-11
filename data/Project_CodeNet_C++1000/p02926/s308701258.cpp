#include <bits/stdc++.h>

using namespace std;

typedef complex<long long> point;
#define EPS 1e-11
#define X real()
#define Y imag()
#define angle(v)    (atan2((v).Y, (v).X))

int dcmp(const double &a, const double &b) {
    if (fabs(a - b) < EPS)
        return 0;
    return ((a > b) << 1) - 1;
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("output.out", "w", stdout);
//	freopen("input.in", "r", stdin);
#endif

    int n;
    scanf("%d", &n);
    vector<point> pts;
    vector<double> angles;
    vector<int> sorted;
    for (int i = 0; i < n; i++) {
        long long x, y;
        scanf("%lld %lld", &x, &y);
        pts.push_back(point(x, y));
        angles.push_back(angle(point(x, y)));
        sorted.push_back(i);
    }


    sort(sorted.begin(), sorted.end(), [&](int a, int b) {
        double a1 = (angles[a]), a2 = (angles[b]);
        int cp = dcmp(a1, a2);
        return cp < 0;
    });

    long long res = 0;
    for (int i = 0; i < n; i++) {
        long long dx = 0, dy = 0;
        for (int j = 0; j < n; j++) {
            dx += pts[sorted[(i + j) % n]].X;
            dy += pts[sorted[(i + j) % n]].Y;
            res = max(res, dx * dx + dy * dy);
        }
    }
    printf("%.20lf\n", sqrt(res));

    return 0;
}
