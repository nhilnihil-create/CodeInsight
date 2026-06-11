#include <stdio.h>
#include <math.h>

int main(){
    double pi = acos(-1);
    double r;
    
    scanf("%lf", &r);
    
    printf("%f %f\n", pi * r * r, 2 * pi * r);
    
    return 0;
}