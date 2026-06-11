#include <iostream>
#include <math.h>
using namespace std;
int main(void){
    // Here your code !
    double r;
    scanf("%lf",&r);
    double ans1 = M_PI*r*r;
    double ans2 = M_PI*2*r;
    printf("%lf %lf",ans1,ans2);
}