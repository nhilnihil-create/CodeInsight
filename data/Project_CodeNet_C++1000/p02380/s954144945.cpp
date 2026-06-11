#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

int main()
{
  double a,b,c,h,S,C;

  cin>>a>>b>>C;
  S=(a*b*sin((C/180)*M_PI))/2;
  printf("%.8f\n",S);
  c=sqrt(a*a+b*b-2*a*b*cos((C/180)*M_PI));
  printf("%.8f\n",a+b+c);
  h=2*S/a;
  printf("%.8f\n",h);
  return 0;
}