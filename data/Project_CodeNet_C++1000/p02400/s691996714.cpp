#include<iostream>
#include<cstdio>
using namespace std;
int main(){
double a,b,b2,p=3.14159265358979323846;
    scanf("%lf",&a);
    b=a*a*p;
    b2=2*a*p;
    printf("%.6f %.6f",b,b2);
    return 0;
}