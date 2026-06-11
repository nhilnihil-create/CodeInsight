#include <cstdio>
#include <cmath>

int main(){
    double x1,x2,y1,y2;
    scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
    double x = pow(x1-x2,2);
    double y = pow(y1-y2,2);
    double distance = sqrt(x + y);
    printf("%.8lf\n",distance);

    return 0;
}
