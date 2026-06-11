#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
main(){
  double x1,y1,x2,y2,x=0,y=0;
  double kekka;
  cin >> x1 >> y1 >> x2 >> y2;
  x=x2-x1;
  y=y2-y1;
  kekka=sqrt(x*x+y*y);
  printf("%.8f\n",kekka);
}