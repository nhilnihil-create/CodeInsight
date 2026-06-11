#include <bits/stdc++.h>

using namespace std;

int main() { 
  double x1, y1, x2, y2;
  scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
  printf("%f\n", sqrt(abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2)));
  return 0;
}

