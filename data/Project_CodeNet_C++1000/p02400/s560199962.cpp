#include <iostream>
#include <cstdio>
using namespace std;
#define PI 3.141592653589

double r;

int main() {
  cin >> r;
  printf("%f %f\n", PI*r*r, 2*PI*r);
}