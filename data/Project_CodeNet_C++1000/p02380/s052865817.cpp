#include <stdio.h>
#include <math.h>

double toRadian(int degree)
{
    return (degree / (180 / M_PI));
}

int main()
{
    int a, b, C;
    scanf("%d%d%d", &a, &b, &C);

    double S, L, h;
    S = (double)(a * b * sin(toRadian(C)) / 2);
    double c = sqrt(pow(a, 2) - 2*a*b*cos(toRadian(C)) + pow(b, 2));
    L = (double)(a + b + c);
    h = (double)(2 * S / a);
    printf("%lf\n%lf\n%lf\n", S, L, h);

    return 0;
}
