#include <cstdio>
#include <math.h>
double a, b, C;
double PI = acos(-1);

int main()
{
    scanf("%lf %lf %lf", &a, &b, &C);
    double rad = C * PI / 180;
    double S = a * b * sin(rad) / 2.00000000;
    double L = a + b + sqrt(a * a + b * b - 2 * a * b * cos(rad));
    double h = b * sin(rad);
    printf("%.8f %.8f %.8f\n", S, L, h);
}
