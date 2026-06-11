#include "bits/stdc++.h"
using namespace std;
int main(){
    double a,b,c,pi,S,L,h;
    cin >> a >> b >> c;
    pi = acos(-1.);
    c = c/180*pi;
    S = 0.5*a*b*sin(c);
    L=a+b+sqrt(a*a+b*b-2.0*a*b*cos(c));
    h = b*sin(c);
    printf("%.4lf\n%.4lf\n%.4lf\n",S,L,h);
    return 0;
}
