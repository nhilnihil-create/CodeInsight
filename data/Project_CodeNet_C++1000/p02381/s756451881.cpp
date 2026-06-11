#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

inline double calc_std(const vector<int>& v, double m) {
  double r = 0.0;
  for (auto s : v) {
    const auto d = static_cast<double>(s) - m;
    r += d * d;
  }
  return sqrt(r / v.size());
}

int main() {
  int n;
  for (;;) {
    cin >> n;
    if (!n)
      break;

    vector<int> v(n, 0);
    double m = 0.0;
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      m += v[i];
    }
    m /= n;
    printf("%.8f\n", calc_std(v, m));
  }
  return 0;
}