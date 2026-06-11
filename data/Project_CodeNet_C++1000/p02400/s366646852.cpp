#include <iostream>
#include <array>
#include <cstdio>
using namespace std;

int main(int argc, char *argv[]){
  double const pi = 3.141592653589;
  double r,c,rim;
  cin >> r;
  c = pi * (r * r);
  rim = 2*pi*r;
  printf("%lf %lf\n",c, rim);
  // cout << d << " " << r << " " << endl;
  return 0;
}