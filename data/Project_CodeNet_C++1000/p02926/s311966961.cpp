#include <bits/stdc++.h>

using namespace std;

struct Point {
    long long x, y;
    long long sign;
    Point() {}
    friend istream& operator>>(istream& in, Point& p) {
        in >> p.x >> p.y;
        if (p.y < 0 || (p.y == 0 && p.x < 0)) {
            p.x *= -1;
            p.y *= -1;
            p.sign = -1;
        } else {
            p.sign = 1;
        }
        return in;
    }
    bool operator<(const Point& o) const {
        return y*o.x < o.y*x || (y*o.x == o.y*x && sign > o.sign);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<Point> points(n);
    for (Point& point : points) {
        cin >> point;
    }
    points.resize(remove_if(points.begin(), points.end(), [](Point& p) { return p.x == 0 && p.y == 0; }) - points.begin());
    n = (int) (points.end() - points.begin());
    sort(points.begin(), points.end());
    long long x = 0, y = 0;
    for (Point& point : points) {
        if (point.sign == 1) {
            x += point.x;
            y += point.y;
        }
    }
    long long best = 0;
    auto update_best = [&]() {
        best = max(best, x*x + y*y);
    };
    update_best();
    for (Point& point : points) {
        x -= point.x;
        y -= point.y;
        update_best();
    }
    for (Point& point : points) {
        x += point.x;
        y += point.y;
        update_best();
    }
    cout << setprecision(30) << sqrt(best) << endl;
    return 0;
}
