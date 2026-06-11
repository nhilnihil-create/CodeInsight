#include <stdio.h>
#include <math.h>
int main()
{
    double i;

    scanf("%lf", &i);
    printf("%lf %lf\n", i*i*M_PI, i*2*M_PI);
    return 0;
}