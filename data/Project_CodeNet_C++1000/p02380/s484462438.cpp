#include <cstdio>
#include <cmath>

int main(void){
    int a, b, deg;
    scanf("%d %d %d", &a, &b, &deg);

    double rad = deg * acos(-1) / 180;
    double h = b * sin(rad);
    double c = sqrt(a * a + b * b - 2 * a * b * cos(rad));

    printf("%lf\n", a * h / 2);
    printf("%lf\n", a + b + c);
    printf("%lf\n", h);

    return 0;
}