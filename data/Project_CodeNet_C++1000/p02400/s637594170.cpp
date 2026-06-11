#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
  double r;
  cin >> r;

  double S = r * r * M_PI;
  double shu = 2 * r * M_PI;

   printf("%.5f %.5f", S,shu);
}