#include<iostream>
#include<stdio.h>
#include<cmath>
 
using namespace std;
int main () {
    double a,b,C;
    cin >> a >> b >> C;
    printf("%.6f\n",a*b*sin(C*M_PI/180)/2);
    printf("%.6f\n",a+b+sqrt(a*a+b*b-2*a*b*cos(C*M_PI/180)));
    printf("%.6f\n",b*sin(C*M_PI/180));
}
