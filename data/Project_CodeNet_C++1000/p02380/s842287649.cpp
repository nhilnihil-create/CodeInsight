#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
    int a, b, C;
    double c, S, L, h, rad;
    cin >> a >> b >> C;
    
    double PI = acos(-1);
    rad = C*PI/180.0;
    
    S = a*b*sin(rad)/2.0;
    c = sqrt(a*a + b*b - 2*a*b*cos(rad));
    L = a+b+c;
    h = 2*S/a;
    
    printf("%f\n", S);
    printf("%f\n", L);
    printf("%f\n", h);
    
    return 0;
}