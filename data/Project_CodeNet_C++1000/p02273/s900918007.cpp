#include <bits/stdc++.h>
using namespace std;

typedef vector<pair<double, double> > VP;
typedef pair<double, double> P;


VP sub(double ax, double ay, double bx, double by) {
    VP ret;
    ret.emplace_back(make_pair((ax * 2 + bx) / 3, (ay * 2 + by) / 3));
    ret.emplace_back(make_pair((ax + bx) / 2 - (by - ay) / (2 * sqrt(3)), (ay + by) / 2 + (bx - ax) / (2 * sqrt(3))));
    ret.emplace_back(make_pair((ax + bx * 2) / 3, (ay + by * 2) / 3));
    return ret;
}


VP f(int n, VP v) {
    if (n == 0) return v;
    VP next;
    next.emplace_back(v[0]);
    for (int i = 0; i < v.size() - 1; ++i) {
        P a = v[i], b = v[i + 1];
        for (auto p : sub(a.first, a.second, b.first, b.second)) {
            next.emplace_back(p);
        }
        next.emplace_back(b);
    }
    return f(n - 1, next);
}

int main() {
    int n;
    cin >> n;
    VP a;
    a.emplace_back(make_pair(0.0, 0.0));
    a.emplace_back(make_pair(100.0, 0.0));
    a = f(n, a);
    for (P p : a) {
        printf("%.9lf %.9lf\n", p.first, p.second);
    }
    return 0;
}