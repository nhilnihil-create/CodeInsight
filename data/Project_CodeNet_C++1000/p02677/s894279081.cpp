#include <iostream>
#include <cmath>
#include <math.h>
// #include <numbers> // C++20
#include <bits/stdc++.h>

int main()
{
  int A, B, H, M;
  std::cin >> A >> B >> H >> M;

  // float pi = std::numbers::pi<float>;
  double pi = M_PI;
  double theta_h = pi / 2 - 2 * pi * double(H) / 12 - 2 * pi / 12 * double(M) / 60;
  double theta_m = pi / 2 - 2 * pi * double(M) / 60;

  double d = sqrt(
      std::pow((double)(A * std::cos(theta_h) - B * std::cos(theta_m)), 2) +
      std::pow((double)(A * std::sin(theta_h) - B * std::sin(theta_m)), 2));

  std::cout << std::fixed << std::setprecision(11)  << d << std::endl;

  return 0;
}
