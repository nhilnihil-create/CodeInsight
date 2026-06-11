#include <cstdio>
#include <cmath>
#include <complex>
using namespace std;

typedef complex<double> P;

void koch(int n, P p1, P p2)
{
    if (n == 0)
        return;

    P s = p1 + (p2 - p1) / 3.0;
    P t = p1 + (p2 - p1) / 3.0 * 2.0;
    P u = s + (t - s) * polar(1.0, M_PI * 1 / 3);
    koch(n - 1, p1, s);
    printf("%.8f %.8f\n", s.real(), s.imag());
    koch(n - 1, s, u);
    printf("%.8f %.8f\n", u.real(), u.imag());
    koch(n - 1, u, t);
    printf("%.8f %.8f\n", t.real(), t.imag());
    koch(n - 1, t, p2);
}

int main()
{
    int n;
    scanf("%d", &n);

    printf("%.8f %.8f\n", 0., 0.);
    koch(n, P(0, 0), P(100, 0));
    printf("%.8f %.8f\n", 100., 0.);

    return 0;
}