#include <cstdio>
#include <cmath>

int main()
{
    double a, b, C, c;
    double pi = 4*atan(1), theta;
    double S, L, h;

    scanf("%lf %lf %lf", &a, &b, &C);

    theta = C * pi / 180.;

    h = b * fabs(sin(theta));
    S = 0.5 * a * h;
    c = sqrt(a*a + b*b - 2*a*b*cos(theta));
    L = a + b + c;

    printf("%lf %lf %lf\n", S, L, h);
    return 0;
}