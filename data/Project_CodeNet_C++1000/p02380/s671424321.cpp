#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
    int a,b,C;
    double c,S,L,H,rad;
    double pi = acos(-1);
    cin >> a >> b >> C;
    rad = C*pi/180;
    S = a*b*sin(rad)/2;
    c = sqrt(a*a+b*b-2*a*b*cos(rad));
    L = S*2/a;
    printf("%.5f\n%.5f\n%.5f\n",S,a+b+c,L);
    return 0;
}
