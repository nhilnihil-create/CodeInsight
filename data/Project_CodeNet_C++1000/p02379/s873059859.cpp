#include <stdio.h>
#include <math.h>

#define SQ(X) ((X)*(X))

int main(){
    double x1, x2, y1, y2;
    double dx, dy;
    
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    dx = x1-x2;
    dy = y1-y2;
    printf("%f\n", sqrt(SQ(dx)+SQ(dy)));

    return 0;
}