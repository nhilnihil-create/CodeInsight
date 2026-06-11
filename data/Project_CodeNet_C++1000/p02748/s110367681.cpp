#include <iostream>
#include <vector>

int main() {
  auto min = [](auto x, auto y) { return (x < y) ? x : y; };
  auto argmin = [&min](std::vector<int>& v) {
    int res{2000000000};
    for (auto&& e : v) res = min(res, e);
    return res;
  };

  int A, B, M;
  std::cin >> A >> B >> M;
  std::vector<int> a(A), b(B);
  for (int i = 0; i < A; i++) std::cin >> a[i];
  for (int i = 0; i < B; i++) std::cin >> b[i];

  int res{argmin(a) + argmin(b)};
  for (int i = 0; i < M; i++) {
    int x, y, c;
    std::cin >> x >> y >> c;
    x--;
    y--;
    res = min(res, a[x] + b[y] - c);
  }
  printf("%d", res);
}