#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
main(){
  double a,b,C;
  double S,L,h;
  cin >> a >> b >> C ;
  C=C/180*M_PI;
  S=(a*b*sin(C))/2;
  L=a+b+sqrt(a*a+b*b-2*a*b*cos(C));
  h=b*sin(C);
  printf("%.8f\n%.8f\n%.8f\n",S,L,h);
}