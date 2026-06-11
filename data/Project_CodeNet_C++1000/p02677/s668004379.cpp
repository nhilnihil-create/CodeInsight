#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
double Pi = 3.14159265358979323846;
double dis(double a, double b, double deg) {
    //printf("a = %f b = %f deg = %f\n",a,b,deg);
    return sqrt(a*a + b*b - 2*a*b*cos(Pi*deg/180.0));
}

int main() {
    double h, w, a, b;
    cin >> a >> b >> h >> w;
    double degh,degw;
    degh = h*30.0+w/2.0;
    degw = w*6.0;
    printf("%.16f\n",dis(a,b,fabs(degh-degw)));
}