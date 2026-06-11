#include <iostream>
#include <cmath>
#include <iomanip>

const double PI = 3.1415926535897932384626;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  double A, B, H, M;  std::cin >> A >> B >> H >> M;
  double ma = M*6;
  double ha = H*30 + ma/12;

  double xa = A*std::cos(ma*PI / 180.0);
  double ya = A*std::sin(ma*PI / 180.0);
  double xb = B*std::cos(ha*PI / 180.0);
  double yb = B*std::sin(ha*PI / 180.0);

  double dx = xa - xb;
  double dy = ya - yb;
  std::cout << std::setprecision(10) << std::fixed << std::sqrt(dx*dx + dy*dy) << "\n";

  return 0;
}
