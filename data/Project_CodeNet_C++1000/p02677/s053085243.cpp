#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <iomanip>

typedef long long ll;

int main(){
  ll A, B, H, M;
  std::cin >> A >> B >> H >> M;
  double pi = 3.14159265358979323846;
  double minutes = H * 60 + M;

  double angle = std::fabs((60 * H - 11 * M) * pi / 360);
  double c = std::sqrt(A * A + B * B - 2 * A * B * std::cos(angle));
  std::cout << std::setprecision(16) << c << std::endl;
  return 0;
}
