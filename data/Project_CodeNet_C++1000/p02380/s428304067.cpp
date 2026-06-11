#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main(){
 double pi,s,a,b,c,l,deg,rad,h;

 cin >> a >> b >> deg;

 pi = acos(-1);
 rad = deg * pi / 180;

 s = a * b * sin(rad) / 2;

 c = sqrt(a*a + b*b - 2 * a * b * cos(rad));

 l = a+b+c;

 h = s / a * 2;

 printf("%lf\n%lf\n%lf\n", s, l, h);

 return 0;
}