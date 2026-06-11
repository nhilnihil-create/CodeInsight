#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

const double cos60=0.500000000000000;
const double sin60=0.866025403784439;

void koch_snowflake(size_t n, pair<double, double> p1, pair<double, double> p2) {
    if (!n) return;

    pair<double, double> s, t, u;
    s.first = (2*p1.first + p2.first) / 3.0;
    s.second = (2*p1.second + p2.second) / 3.0;
    t.first = (p1.first + 2*p2.first) / 3.0;
    t.second = (p1.second + 2*p2.second) / 3.0;
    u.first = (t.first-s.first)*cos60 - (t.second-s.second)*sin60 + s.first;
    u.second = (t.first-s.first)*sin60 + (t.second-s.second)*cos60 + s.second;

    koch_snowflake(n-1, p1, s);
    printf("%.12f %.12f\n", s.first, s.second);
    koch_snowflake(n-1, s, u);
    printf("%.12f %.12f\n", u.first, u.second);
    koch_snowflake(n-1, u, t);
    printf("%.12f %.12f\n", t.first, t.second);
    koch_snowflake(n-1, t, p2);
}

int main() {
    size_t n;
    scanf("%zu", &n);

    pair<double, double> p1(0.0, 0.0), p2(100.0, 0.0);

    printf("%.12f %.12f\n", 0.0, 0.0);
    koch_snowflake(n, p1, p2);
    printf("%.12f %.12f\n", 100.0, 0.0);

    return 0;
}