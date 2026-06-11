#include <stdio.h>

int main(void)
{
    double a, b;
    scanf("%lf %lf", &a, &b);
    int l, m;
    double n;
    l = a / b;
    m = a - l * b;
    n = a / b;
    printf("%d %d %f\n", l, m, n);
    return 0;
}