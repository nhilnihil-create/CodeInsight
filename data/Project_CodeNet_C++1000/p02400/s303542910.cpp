#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
  double r,pi,s,l;
  pi = 3.141592653589;

  cin >> r;
  s = pi*r*r;
  l = 2*pi*r;

  printf("%f %f\n",s,l);
  return 0;
}