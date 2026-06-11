#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

#define PI 3.1415926

int main(){

  int a,b,c;
  double S,L,h;

  cin >> a >> b >> c;

  S=(double)a*b*sin((double)c/180*PI)/2;
  h=b*sin((double)c/180*PI);
  
  L= a+b+ sqrt(a*a + b*b - 2*a*b*cos((double)c/180*PI) );

  printf("%.8lf\n%.8lf\n%.8lf\n",S,L,h);

  return 0;
}