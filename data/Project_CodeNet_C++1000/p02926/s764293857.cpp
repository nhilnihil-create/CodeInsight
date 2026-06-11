#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct point {
    double x, y;
    double angle;
};
bool operator<(const point& x0, const point& x1) {
    return x0.angle < x1.angle;  //<で昇順
}

int main() {
    int n;
    double ans = 0;
    cin >> n;
    vector<point> p;
    for (int i = 0; i < n; i++) {
        double x, y, angle;
        cin >> x >> y;
        if (x == 0 && y == 0) continue;
        angle = atan2(y, x);
        p.push_back({x, y, angle});
    }
    sort(p.begin(), p.end());
    n = p.size();
    for (int i = 0; i < n; i++) {
        p.push_back({p[i].x, p[i].y, p[i].angle + M_PI * 2});
    }
    n = p.size();
    for (int i = 0; i < n; i++) {
        double sx = p[i].x, sy = p[i].y;
        ans = max(ans, sqrt(sx * sx + sy * sy));
        for (int j = i + 1; j < n; j++) {
            if (i+n/2 <= j) break;
            sx += p[j].x;
            sy += p[j].y;
            ans = max(ans, sqrt(sx * sx + sy * sy));
        }
    }
    cout << setprecision(20) << ans << endl;
    return 0;
}