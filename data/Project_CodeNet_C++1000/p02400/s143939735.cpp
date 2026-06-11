#include <iostream>
#include <math.h>
#include <map>
using namespace std;
double r,p,q;
int main() {
    scanf("%lf",&r);
    p=r*r*M_PI;
    q=2*r*M_PI;
    printf("%f  %f\n",p,q);
}