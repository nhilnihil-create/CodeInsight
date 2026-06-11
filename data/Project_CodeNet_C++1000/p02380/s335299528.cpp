#include <bits/stdc++.h>
using namespace std;

int main(void) {
    double a,b,corner;
    cin>>a>>b>>corner;
    double s=0.0,l=0.0,h=0.0;
    s=(a*b*sin(corner*M_PI/180.00000000))/2;
    l=a+b+(sqrt(a*a+b*b-2*a*b*cos(corner*M_PI/180.00000000)));
    h=2*s/a;
    printf("%.8f\n",s);
    printf("%.8f\n",l);
    printf("%.8f\n",h);
    return 0;
}