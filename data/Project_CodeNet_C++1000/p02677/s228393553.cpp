#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

double calc_len2(int a, int b, double theta) {
  return a*a + b*b - 2*a*b*cos(theta * M_PI/180);
}

int main() {
  int a, b, h, m;
  cin >> a >> b >> h >> m;
  
  double h_angle = (60*h + m) * 360.0/(12*60);
  double m_angle = m * 360/60;
  
  cout << fixed << setprecision(10) << sqrt(calc_len2(a, b, abs(h_angle - m_angle)));
  
  return 0;
}