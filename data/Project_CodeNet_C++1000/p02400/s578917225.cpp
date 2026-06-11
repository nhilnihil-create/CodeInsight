#include <stdio.h>
#include <math.h>
int main(){
    double r;
    double S,l;
    scanf("%lf",&r);
    S = (double)r*r*M_PI;
    l = (double)2*M_PI*r;
    printf("%lf %lf\n",S,l);
}