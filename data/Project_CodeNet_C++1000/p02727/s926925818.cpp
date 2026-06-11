#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int main() {
  int x, y;
  int a, b, c;
  std::cin >> x >> y;
  std::cin >> a >> b >> c;
  std::vector<long long> p(a), q(b), r(c);
  for (int i = 0; i < a; ++i)
    std::cin >> p[i];
  for (int i = 0; i < b; ++i)
    std::cin >> q[i];
  for (int i = 0; i < c; ++i)
    std::cin >> r[i];

  std::vector<std::pair<long long, int>> v;
  for (int i = 0; i < a; ++i)
    v.push_back(std::make_pair(p[i], 0));
  for (int i = 0; i < b; ++i)
    v.push_back(std::make_pair(q[i], 1));
  for (int i = 0; i < c; ++i)
    v.push_back(std::make_pair(r[i], 2));

  std::sort(v.begin(), v.end(), std::greater<std::pair<long long, int>>());

  int rem = x + y;
  int rem0 = x;
  int rem1 = y;
  long long res = 0;
  for (auto &val : v) {
    long long w = val.first;
    long long c = val.second;

    if (c == 0 && rem0 > 0) {
      res += w;
      rem0 -= 1;
      rem -= 1;
    }
    if (c == 1 && rem1 > 0) {
      res += w;
      rem1 -= 1;
      rem -= 1;
    }
    if (c == 2) {
      res += w;
      rem -= 1;
    }

    if (rem == 0)
      break;
  }
  std::cout << res << std::endl;
}
