#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
  double r;
  cin >> r;
  double s, v, pi;
  pi = 3.14159265358979;
  
  s = r*r*pi;
  v = 2*r*pi;

  printf("%f %f\n", s, v);
}