#include <stdio.h>
#include <math.h>
int main(void){
    double x1,y1,x2,y2;
    scanf("%lf",&x1);
    scanf("%lf",&y1);
    scanf("%lf",&x2);
    scanf("%lf",&y2);
    printf("%.8lf\n",pow((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1),0.5));
    return 0;
}
