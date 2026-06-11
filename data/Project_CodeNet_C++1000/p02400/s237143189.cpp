#include<cstdio>
#include<iostream>
using namespace std;

#define ll long long

int main() {
  double r;
  double pi = 3.141592653589;

  cin >> r;
  
  printf("%.7f %.7f\n", r * r * pi, 2 * pi * r);
  return 0;
}
  