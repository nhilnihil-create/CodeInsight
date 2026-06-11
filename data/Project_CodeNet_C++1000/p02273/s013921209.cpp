#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

const double pi = 3.14159265;

void print(pair<double, double> p) {
    printf("%.8lf %.8lf\n", p.first, p.second);
}

void koch(int n, pair<double, double> p1, pair<double, double> p2) {
    if (n == 0) {
        pair<double, double> end = {100,0};
        print(p1);
        if (p2 == end) print(p2);
    } else {
        pair<double, double> s, t, u;
        s.first = (2 * p1.first + p2.first) / 3;
        s.second = (2 * p1.second + p2.second) / 3;
        t.first = (p1.first + 2 * p2.first) / 3;
        t.second = (p1.second + 2 * p2.second) / 3;
        u.first = (t.first - s.first) * cos(pi/3) - (t.second - s.second) * sin(pi/3) + s.first;
        u.second = (t.first - s.first) * sin(pi/3) + (t.second - s.second) * cos(pi/3) + s.second;
        koch(n-1, p1, s);
        koch(n-1, s, u);
        koch(n-1, u, t);
        koch(n-1, t, p2);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    const pair<double, double> p1 = {0, 0}, p2 = {100, 0};
    koch(n, p1, p2);
}
