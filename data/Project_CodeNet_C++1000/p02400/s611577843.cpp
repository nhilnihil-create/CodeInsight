#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
 double r;
  cin>>r;
  double m,e,pi;
  pi=3.141592653589;
  m=r*r*pi;
  e=2*r*pi;
  printf("%f %f\n",m,e);
  return 0;
}