#include <stdio.h>
#include <math.h>
#define sqr(x) ((x) * (x))

int main(void){
double x1, y1, x2, y2;
scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
printf("%f\n",sqrt(sqr(x2 - x1) + sqr(y2 - y1)));
return 0;
}