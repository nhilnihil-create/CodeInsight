#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

struct Eng {
  Eng(const double th_, const int x_, const int y_) : th(th_), x(x_), y(y_) {}
  double th;
  int x, y;
};

int main() {
  int N;
  std::cin >> N;

  std::vector<Eng> engs;
  for (int i = 0; i < N; i++) {
    int x, y;
    std::cin >> x >> y;
    engs.push_back(Eng(atan2(y, x), x, y));
  }

  std::sort(engs.begin(), engs.end(),
            [](const Eng &a, const Eng &b) -> bool { return a.th < b.th; });

  double max = 0;
  for (int i = 0; i < N; i++) {
    long xsum = engs[i].x, ysum = engs[i].y;
    double pre = xsum * xsum + ysum * ysum;
    if (pre > max) max = pre;
    for (int j = 1; j < N; j++) {
      int k = i + j < N ? i + j : i + j - N;
      xsum += engs[k].x;
      ysum += engs[k].y;
      double tmp = xsum * xsum + ysum * ysum;
      if (tmp > max) max = tmp;
      pre = tmp;
    }
  }

  printf("%0.12f\n", sqrt(max));

  return 0;
}
