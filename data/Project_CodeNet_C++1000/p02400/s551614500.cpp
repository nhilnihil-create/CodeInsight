#include <stdio.h>
int main(void)
{
    double r, area, cir, pi = 3.141592653589;
    scanf("%lf", &r);
    area = r * r * pi;
    cir = 2 * r * pi;
    printf("%f %f\n", area, cir);
    return 0;
}