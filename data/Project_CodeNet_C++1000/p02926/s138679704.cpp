#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

int main() {
    ll N;
    cin >> N;
    struct Point {
        double x, y, rad;
    };

    const double PI = acos(-1);
    vector<Point> points(N);
    for (Point &p : points) {
        cin >> p.x >> p.y;
        p.rad = atan2(p.y, p.x);
    }

    sort(points.begin(), points.end(), [](Point &lhs, Point &rhs) {
        return lhs.rad < rhs.rad;
    });

    double ans = 0;
    for (ll i = 0; i < N; i++) {
        for (ll j = 1; j <= N; j++) {
            //iからj個使う
            double x = 0, y = 0;

            for (ll k = 0; k < j; k++) {
                x += points[(i + k) % N].x;
                y += points[(i + k) % N].y;
            }

            double curr = sqrt(pow(x, 2) + pow(y, 2));
            ans = max(ans, curr);
        }
 }

    cout << setprecision(15) << ans << endl;
}