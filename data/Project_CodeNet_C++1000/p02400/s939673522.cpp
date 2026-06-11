#include <stdio.h>
int main(){
    double r,s,l;
    scanf("%lf",&r);
    s = (double) r*r*3.141592653589;
    l = (double) 2*r*3.141592653589;
    printf("%.6f %.6f\n",s,l);
    return 0;
}