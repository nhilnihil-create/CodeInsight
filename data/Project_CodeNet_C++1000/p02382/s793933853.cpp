#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

inline double manhattan_dist(const vector<int>& x, const vector<int>& y) {
  double r = 0.0;
  for (size_t i = 0; i < x.size(); ++i)
    r += abs(x[i] - y[i]);
  return r;
}

inline double euclid_dist(const vector<int>& x, const vector<int>& y) {
  double r = 0.0;
  for (size_t i = 0; i < x.size(); ++i)
    r += (x[i] - y[i]) * (x[i] - y[i]);
  return sqrt(r);
}

// Minkowski distance when p = 3
inline double minkowski3_dist(const vector<int>& x, const vector<int>& y) {
  double r = 0.0;
  for (size_t i = 0; i < x.size(); ++i) {
    const auto d = abs(x[i] - y[i]);
    r += d * d * d;
  }
  return cbrt(r);
}

inline double chebyshev_dist(const vector<int>& x, const vector<int>& y) {
  int m = 0;
  for (size_t i = 0; i < x.size(); ++i) {
    const auto d = abs(x[i] - y[i]);
    m = max(m, d);
  }
  return static_cast<double>(m);
}

int main() {
  int n;
  vector<int> x;
  vector<int> y;

  cin >> n;
  x.resize(n);
  y.resize(n);

  for (int i = 0; i < n; ++i)
    cin >> x[i];
  for (int i = 0; i < n; ++i)
    cin >> y[i];

  printf("%.6f\n", manhattan_dist(x, y));
  printf("%.6f\n", euclid_dist(x, y));
  printf("%.6f\n", minkowski3_dist(x, y));
  printf("%.6f\n", chebyshev_dist(x, y));
  return 0;
}