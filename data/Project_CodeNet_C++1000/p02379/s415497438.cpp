#include <cstdio>
#include <math.h>

int main()
{
    double x1, y1, x2, y2;
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    double x0 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    printf("%.8f\n", sqrt(x0));
}
