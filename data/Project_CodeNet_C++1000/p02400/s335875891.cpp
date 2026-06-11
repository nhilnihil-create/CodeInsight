#include <cstdio>
#include <cmath>

int main () {
    double r, area, circle;
    scanf("%lf", &r);

    area = r *  r * M_PI;
    circle = 2.0 * r * M_PI;
    printf("%f %f\n", area, circle);
    return 0;
}