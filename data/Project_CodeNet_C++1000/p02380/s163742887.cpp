#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main( ){
  double a,b,c,d,C,s,l,h;
  cin>>a>>b>>C;
  d=C*acos(-1)/180;
  s=a*b*sin(d)/2;
  c=sqrt(pow(a,2)+pow(b,2)-2*a*b*cos(d));
  l=a+b+c;
  h=b*sin(d);
  printf("%f\n%f\n%f\n",s,l,h);
  return 0;
}