#include <cstdio>
#include <iostream>
using namespace std;

int main(){
  const double PI = 3.14159265358979324;
  double r;
  cin >> r;
  printf("%f %f", r*r*PI, 2*PI*r);
  return 0;
}