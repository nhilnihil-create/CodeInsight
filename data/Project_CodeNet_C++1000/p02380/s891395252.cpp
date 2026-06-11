#include <bits/stdc++.h>

using namespace std;

int main() { 
  double a, b, c;
  scanf("%lf %lf %lf", &a, &b, &c);
  c = c / 180.0 * M_PI;
  printf("%f\n%f\n%f\n", 
    a * b * sin(c) / 2.0,
    a + b + sqrt(pow(a * sin(c), 2) + pow(b - a * cos(c), 2)),
    b * sin(c)
  );
  return 0;
}

