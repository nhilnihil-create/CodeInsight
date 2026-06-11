#include <bits/stdc++.h>
using namespace std;

int main() {
  double a, b, C;
  cin >> a >> b >> C;

  double area = (a * b * sin(C*M_PI/180)) / 2;
  double L = a + b + (sqrt(pow(a,2) + pow(b,2) - 2*a*b*cos(C*M_PI/180)));
  double height = b * sin(C*M_PI/180);

  printf("%.5f\n", area);
  printf("%.5f\n", L);
  printf("%.5f\n", height);

  return 0;
}

