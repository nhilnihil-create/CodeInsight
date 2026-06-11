#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;

int main(){
  double a, b, C, S, L, h, rad_C, PI=acos(-1);
  cin>>a>>b>>C;
  rad_C = PI * (C / 180);
  S = 0.5 * a * b * sin(rad_C);
  L = a + b + sqrt(pow(a, 2) + pow(b, 2) - 2*a*b*cos(rad_C));
  h = b * sin(rad_C);
  printf("%.5f\n%.5f\n%.5f\n", S, L, h);
  return 0;
}

