#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main(void){
    double a,b,C,S,L,h;
    cin>>a>>b>>C;
    C*=(3.14159265/180);
    S=(1/2.0)*a*b*sin(C);
    L=a+b+sqrt(a*a+b*b-2*a*b*cos(C));
    h=b*sin(C);
    printf("%.5f\n",S);
    printf("%.5f\n",L);
    printf("%.5f\n",h);
    return 0;
}