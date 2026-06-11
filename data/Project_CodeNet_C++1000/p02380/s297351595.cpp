#include <stdio.h>
#include <math.h>
#define PI 3.14159265359

int main(void)
{
    int a, b;
    double rad, S, L, h, c;
    
    scanf("%d %d %lf", &a, &b, &rad);
    
    rad = (rad / 180) * PI;
    c = sqrt (a * a + b * b - 2 * a * b * cos(rad));

    S = ((double)a * b * sin(rad)) / 2;
    L = a + b + c;
    h = b * sin(rad);
    
    printf("%.5f %.5f %.5f\n", S, L, h);
    
    return 0;
}