#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using coord = std::pair<double, double>;

double len(const coord& line) {
  return std::sqrt(line.first * line.first + line.second * line.second);
}

void Koch(coord start, coord end, uint32_t n) {
  if (n == 0) {
    std::cout << start.first << " " << start.second << std::endl;
    return;
  }

  auto diff = coord(end.first - start.first, end.second - start.second);
  auto s = coord(diff.first / 3 + start.first, diff.second / 3 + start.second);
  auto t = coord(diff.first * 2 / 3 + start.first,
                 diff.second * 2 / 3 + start.second);
  auto u = coord(diff.first / 2 + start.first, diff.second / 2 + start.second);

  auto normal = coord(-diff.second / len(diff), diff.first / len(diff));
  double normal_len = std::sqrt(3) * len(diff) / 6;
  normal = coord(normal_len * normal.first, normal_len * normal.second);

  u = coord(u.first + normal.first, u.second + normal.second);

  Koch(start, s, n - 1);
  Koch(s, u, n - 1);
  Koch(u, t, n - 1);
  Koch(t, end, n - 1);

  return;
}

int main() {
  uint32_t n = 0;
  std::cin >> n;

  std::cout << std::fixed;
  std::cout << std::setprecision(8);

  auto start = coord(0, 0);
  auto end = coord(100, 0);
  Koch(start, end, n);

  std::cout << end.first << " " << end.second << std::endl;
  return 0;
}
