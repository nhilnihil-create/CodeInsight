#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

int main(){
    double a, b, c;
    double rad;
    double PI = acos(-1);
    
    cin >> a >> b >> c;
    rad = c * PI / 180;
    printf("%lf\n",a * b * sin(rad) * 0.5);
    printf("%lf\n",sqrt(a*a + b * b - 2*a*b*cos(rad)) + b + a);
    printf("%lf\n",a * b * sin(rad) / a);
    
    return 0;
}