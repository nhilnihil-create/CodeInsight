#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
  int a,b;
  double C,c;
  double S,L,h;
  
  cin >> a >> b >> C;
  double PI = acos(-1); //cos(PI rad) = -1 
  C = C * PI / 180;
  S = a * b * sin(C) / 2;
  c = sqrt( a*a + b*b - 2*a*b*cos(C) );
  L = a + b + c;
  h = b * sin(C);
  printf ("%lf\n%lf\n%lf",S,L,h);
  
  return 0;
}
