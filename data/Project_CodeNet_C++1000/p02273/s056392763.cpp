#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    using Point = pair<double, double>;
    function<vector<Point>(int, Point, Point)> f =
        [&f](int d, Point p1, Point p2) -> vector<Point> {
        if (d == 0) {
            return {};
        }

        auto s = Point((p1.first * 2.0 + p2.first) / 3.0,
                       (p1.second * 2.0 + p2.second) / 3.0);
        auto t = Point((p1.first + p2.first * 2.0) / 3.0,
                       (p1.second + p2.second * 2.0) / 3.0);
        auto u = Point((t.first - s.first) * cos(M_PI / 3.0) -
                           (t.second - s.second) * sin(M_PI / 3.0) + s.first,
                       (t.first - s.first) * sin(M_PI / 3.0) +
                           (t.second - s.second) * cos(M_PI / 3.0) + s.second);

        vector<Point> r;
        {
            auto rr = f(d - 1, p1, s);
            r.insert(end(r), begin(rr), end(rr));
        }
        r.push_back(s);
        {
            auto rr = f(d - 1, s, u);
            r.insert(end(r), begin(rr), end(rr));
        }
        r.push_back(u);
        {
            auto rr = f(d - 1, u, t);
            r.insert(end(r), begin(rr), end(rr));
        }
        r.push_back(t);
        {
            auto rr = f(d - 1, t, p2);
            r.insert(end(r), begin(rr), end(rr));
        }
        return r;
    };

    int n;
    cin >> n;

    auto r = f(n, Point(0.0, 0.0), Point(100.0, 0.0));
    r.insert(begin(r), Point(0.0, 0.0));
    r.emplace_back(100.0, 0.0);
    for (auto&& i : r) {
        cout << setprecision(8) << fixed << i.first << ' ' << i.second << endl;
    }
}