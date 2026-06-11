#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main(){
  int a, b, C;
  double rad, S, L, h;
  cin >> a >> b >> C;
  rad = C * acos(-1) / 180;
  S = a * b * sin(rad) / 2;
  L = a + b + sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(rad));
  h = b * sin(rad);
  printf("%f\n%f\n%f\n", S, L, h);

  return 0;
}