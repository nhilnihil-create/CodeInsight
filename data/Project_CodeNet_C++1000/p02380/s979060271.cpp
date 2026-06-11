#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main(){
  double a,b,theta;
  cin >> a >> b >> theta;
  double S = a*b*sin((theta*M_PI)/180) / 2 ;
  double L = a + b + sqrt(a*a + b*b - 2*a*b*cos(theta*M_PI/180));
  double h = b *sin((theta*M_PI)/180);
  printf("%.10f\n",S);
  printf("%.10f\n",L);
  printf("%.10f\n",h);
}