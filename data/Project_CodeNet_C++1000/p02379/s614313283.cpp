#include <stdio.h>
#include <math.h>

int main(){
    double x, y, x1, y1, x2, y2;
    
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    
    x = x2 - x1;
    y = y2 - y1;
    
    printf("%f\n", sqrt(x * x + y * y));
    
    return 0;
}
