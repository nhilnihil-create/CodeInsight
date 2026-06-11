#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, C;

    scanf("%d %d %d", &a, &b, &C);

    printf("%lf\n", (double)1/2*a*b*sin(C*M_PI/180.0));
    printf("%lf\n", (double)a+b+sqrt(pow(a,2)+pow(b,2)-2*a*b*cos(C*M_PI/180.0)));
    printf("%lf\n", (double)b*sin(C*M_PI/180.0));
    return 0;
}