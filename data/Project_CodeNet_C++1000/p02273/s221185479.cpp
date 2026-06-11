#include <cstdio>
#include <cmath>
#include <utility>

void rec(int n, std::pair<double, double> p, std::pair<double, double> q) {
  if (n == 0) {
    printf("%f %f\n", q.first, q.second);
    return;
  }
  auto d = std::make_pair((q.first - p.first) / 3, (q.second - p.second) / 3);
  auto e = std::make_pair(d.first * 0.5 - d.second * sqrt(3) / 2, d.first * sqrt(3) / 2 + d.second * 0.5);
  auto r = std::make_pair(p.first + d.first, p.second + d.second);
  auto s = std::make_pair(r.first + e.first, r.second + e.second);
  auto t = std::make_pair(q.first - d.first, q.second - d.second);
  rec(n - 1, p, r);
  rec(n - 1, r, s);
  rec(n - 1, s, t);
  rec(n - 1, t, q);
}

int main() {
  size_t n;
  scanf("%zu", &n);
  printf("%f %f\n", 0.0, 0.0);
  rec(n, std::make_pair(0, 0), std::make_pair(100, 0));
  return 0;
}