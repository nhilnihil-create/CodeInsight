#include<stdio.h>
#include<stdbool.h>
#include <math.h>
int main(void){
 double x1,y1,x2,y2;
 scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
 printf("%.8f\n",sqrt(pow(fabs(x1-x2),2)+pow(fabs(y1-y2),2)));
 return 0;
}

