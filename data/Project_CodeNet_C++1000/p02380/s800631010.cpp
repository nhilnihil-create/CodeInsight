#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int main(){
    double a,b,S,L,h,rad;
    int c;
    double PI = acos(-1);
    cin>>a>>b>>c;
    rad = c*PI/180;
    S = a*b*sin(rad)/2;
    L = a+b+sqrt(a*a+b*b-2*a*b*cos(rad));
    h = 2*S/a;
    printf("%.8lf\n", S);
    printf("%.8lf\n", L);
    printf("%.8lf\n", h);
return 0;
}
