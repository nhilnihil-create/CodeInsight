#include<stdio.h>

int main(){
    double r;    
    scanf("%lf", &r);
    double pi = 3.141592653589;
    double area, circ;
    area = pi * r * r;
    circ  = 2 * pi * r; 
    printf("%f %f\n", area, circ);

    return 0;
}