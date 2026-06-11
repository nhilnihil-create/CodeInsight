//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_10_B
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
int main(){

  int a, b;
  double theta;
  cin >> a >> b >> theta;
  theta = M_PI*theta/180;

  double S = a * b * sin(theta)/2;

  double c = sqrt(a*a + b*b - 2*a*b*cos(theta));
  double L = a + b + c;
  double h = S*2/a;
  printf("%.8lf \n", S);
  printf("%.8lf \n", L);
  printf("%.8lf \n", h);
}