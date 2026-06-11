#include<iostream>
#include<cstdio>
using namespace std;
int main(){
  double r,x,y;
  cin>> r;
  x=r*r*3.141592653589;
  y=2*r*3.141592653589; 
  printf("%.6lf %.6lf\n", x,y);
    
  return 0;
}