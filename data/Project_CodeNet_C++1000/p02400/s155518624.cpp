#include <cstdio>
#include <cmath>
 
int main(void){
    double r, pi = acos(-1);
    scanf("%lf", &r);
    printf("%.5f %.5f\n", pi * r * r, 2 * pi * r);
    return 0;
}