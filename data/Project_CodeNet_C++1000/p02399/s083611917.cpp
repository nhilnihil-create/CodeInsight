#include<iostream>
#include<stdio.h>
using namespace std;

int main(void){

  int a,b,d,r;
  double a1,b1,f;

  cin >> a >> b;

  d = a / b;
  r = a % b;
  a1 = (double)a;
  b1 = (double)b;
  f = a1 / b1;

  cout << d << " " << r << " ";
  printf("%lf\n",f);

  return 0;

}