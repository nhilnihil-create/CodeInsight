#include <stdio.h>
#include <math.h>
int main(){
    double x,y,a,b;
    scanf("%lf%lf%lf%lf",&x,&y,&a,&b);
    printf("%lf\n",sqrt((x-a)*(x-a)+(y-b)*(y-b)));
}