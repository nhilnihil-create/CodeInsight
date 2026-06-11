#include <bits/stdc++.h>
#include <stdio.h>
//#include <math.h>

int main() {
  int a, b, h, m; std::cin >> a >> b >> h >> m;
  double m_theta = 6 * m;
  double h_theta = 30 * h + m / 2.0;
  double theta = std::abs(m_theta - h_theta);
  if (theta > 180) theta = 360 - theta;
  double c_squ = a*a + b*b - 2*a*b*std::cos(theta * 3.1415926535897932 / 180.0);
  double c = sqrt(c_squ);

  printf("%.11lf\n", c);
  return 0;
  
}
