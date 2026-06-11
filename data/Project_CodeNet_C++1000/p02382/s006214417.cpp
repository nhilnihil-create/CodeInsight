#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

static double CalcMinkowskiDistance(const int* x, const int* y, int n, int p) {
  long d = 0;
  for (int i = 0; i < n; ++i) {
    const long e = x[i] - y[i] >= 0 ? x[i] - y[i] : y[i] - x[i];
    long r = 1;
    for (int j = 0; j < p; ++j) {
      r *= e;
    }
    d += r;
  }
  return pow(static_cast<double>(d), 1.0 / static_cast<double>(p));
}

static double CalcManhattanDistance(const int* x, const int* y, int n) {
  long d = 0;
  for (int i = 0; i < n; ++i) {
    const long e = x[i] - y[i] >= 0 ? x[i] - y[i] : y[i] - x[i];
    d += e;
  }
  return static_cast<double>(d);
}

static double CalcEuclideanDistance(const int* x, const int* y, int n) {
  double d = 0.0;
  for (int i = 0; i < n; ++i) {
    d += static_cast<double>(x[i] - y[i]) * static_cast<double>(x[i] - y[i]);
  }
  return sqrt(d);
}

static double CalcChebyshevDistance(const int* x, const int* y, int n) {
  long d = 0;
  for (int i = 0; i < n; ++i) {
    const long e = x[i] - y[i] >= 0 ? x[i] - y[i] : y[i] - x[i];
    d = max(d, e);
  }
  return static_cast<double>(d);
}

int main() {
  int n;
  cin >> n;

  int x[100] = {0};
  int y[100] = {0};
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  for (int i = 0; i < n; ++i) {
    cin >> y[i];
  }

  printf("%f\n", CalcManhattanDistance(x, y, n));
  printf("%f\n", CalcEuclideanDistance(x, y, n));
  printf("%f\n", CalcMinkowskiDistance(x, y, n, 3));
  printf("%f\n", CalcChebyshevDistance(x, y, n));
  return 0;
}