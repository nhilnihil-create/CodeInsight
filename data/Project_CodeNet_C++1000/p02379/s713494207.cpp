#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main(){
  double x1,y1,x2,y2,a,b;
  double distance;
  cin >> x1 >> y1 >> x2 >> y2 ;
  a=x2-x1;
  b=y2-y1;
  distance = sqrt(a*a+b*b);
  printf("%.8f\n",distance);
  return 0;
}