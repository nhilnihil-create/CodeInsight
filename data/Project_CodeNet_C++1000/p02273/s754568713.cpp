#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <complex>

using namespace std;

const double pi=3.141592653589793;

void koch_snowflake(size_t n, complex<double> p1, complex<double> p2) {
    if (!n) return;

    complex<double> s, t, u;
    s = (2.0*p1 + p2) / 3.0;
    t = (p1 + 2.0*p2) / 3.0;
    u = (t-s)*polar(1.0, 60*pi/180)+s;

    koch_snowflake(n-1, p1, s);
    printf("%.12f %.12f\n", s.real(), s.imag());
    koch_snowflake(n-1, s, u);
    printf("%.12f %.12f\n", u.real(), u.imag());
    koch_snowflake(n-1, u, t);
    printf("%.12f %.12f\n", t.real(), t.imag());
    koch_snowflake(n-1, t, p2);
}

int main() {
    size_t n;
    scanf("%zu", &n);

    complex<double> p1(0.0, 0.0), p2(100.0, 0.0);

    printf("%.12f %.12f\n", 0.0, 0.0);
    koch_snowflake(n, p1, p2);
    printf("%.12f %.12f\n", 100.0, 0.0);

    return 0;
}