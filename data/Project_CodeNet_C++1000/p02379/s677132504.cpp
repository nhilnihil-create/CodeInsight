#include <iostream>
#include <cstdio>
#include <cmath>

int main(){
  double x1, y1, x2, y2;
  double dist;
  std::cin >> x1 >> y1 >> x2 >> y2;

  dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

  printf("%.8lf\n", dist);
}

