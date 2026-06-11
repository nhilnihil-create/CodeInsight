#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
  double x1, y1, x2, y2, x, y;
  cin>>x1>>y1>>x2>>y2;
  x=x2-x1;
  y=y2-y1;
  printf("%f\n", sqrt(x*x+y*y));
  return 0;
}