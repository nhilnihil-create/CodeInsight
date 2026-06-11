#include <iostream>
using namespace std;
#include <math.h>
#include <stdio.h>
#define PI 3.141592653589
int main(void){
        int a,b;
        double S,L,h,deg,C,c;
        cin>>a>>b>>deg;
        C=deg*PI/180;
        S=a*b*sin(C)/2;
        c = sqrt(a*a + b*b - 2*a*b*cos(C));
        L=a+b+c;
        h=b*sin(C);
        printf("%f\n%f\n%f\n",S,L,h);
        return 0;
}
