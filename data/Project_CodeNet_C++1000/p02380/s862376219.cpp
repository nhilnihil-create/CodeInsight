#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
  int a, b, C;
  double S, L, h;
  double PI=acos(-1);

  cin>>a>>b>>C;
  S=a*b*sin(C*PI/180.0)/2;
  L=a+b+sqrt(a*a+b*b-2*a*b*cos(C*PI/180.0));
  h=b*sin(C*PI/180.0);

  printf("%f\n%f\n%f\n", S, L, h);
  return 0;
}