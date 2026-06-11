#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main(){
 int a, b, c;
 cin >> a >> b >> c;
 
 double S, L, h;
 double Pi = 3.141592653589;
 S = 0.5 * a * b * sin( Pi * c / 180.0);
 L = a + b + sqrt(a * a + b * b -2.0 * a * b * cos(Pi * c / 180.0));
 h = 2.0 * S / a;
 printf("%f\n %f\n %f\n", S, L, h);
 
 return 0;
}
