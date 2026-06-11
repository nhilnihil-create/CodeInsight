#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main(){
  double a,b;
  int c;
  cin >> a >> b >> c;
  
  double S = 0.5*a*b*sin( c * M_PI / 180 );
  double L = a+b+((sqrt(a*a+b*b-2*a*b* cos( c * M_PI / 180 ))));
  
  printf("%.8f\n",S);
  printf("%.8f\n",L);
  printf("%.8f\n",2*(S/a));
  
  return 0;
}