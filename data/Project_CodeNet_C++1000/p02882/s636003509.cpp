#include <bits/stdc++.h>
using namespace std;
//NOT TO SUBMIT IN WRONG PLACE OR BY WRONG COMPILER
//ABC 177, task a, 2020/09/010
//ms,
/*
*/

#define EPS DBL_EPSILON

bool spill_or_not(double, double, double, double);

bool spill_or_not(double theta, double a, double b, double x){
  double v;
  if(b-tan(theta)*a>=0) v=a*a*(2.0*b-tan(theta)*a)/2.0;
  else v= a*b*b/tan(theta)/2.0;

  if(x>v) return true;
  else return false;
}

int main(void){
  int a, b, x;
  cin >>a >>b >>x;

  double ng=0.0-EPS;
  double ok=M_PI/2.0+EPS;
  while(abs(ok-ng)>0.00000001){
    double mid=(ok+ng)/2.0;
    if(spill_or_not(mid, a+0.0, b+0.0, x+0.0)) ok=mid;
    else ng=mid;
  }

  printf("%2.15f", ok/M_PI*180.0);
  return 0;
}
/*
*/
