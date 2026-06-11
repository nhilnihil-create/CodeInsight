#include <stdio.h>
#include <math.h>

int main(void)
{
    double r;
    
    scanf("%lf", &r);
    printf("%.6lf %.6lf", (r * r * M_PI), (2 * r * M_PI));
         
    return 0;
}
