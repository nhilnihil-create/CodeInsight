#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
#define PI 3.141592653589
int main(int argc,char* argv[])
{
  double a,b,c,S,L,h;
  cin >> a >> b >> c;
  S=a*b*sin(PI*c/180)*0.5;
  L=a+b+sqrt(pow(a,2.0)+pow(b,2.0)-2*a*b*cos(PI*c/180));
  h=b*sin(PI*c/180);
  printf("%.8lf\n%.8lf\n%.8lf\n",S,L,h);
}