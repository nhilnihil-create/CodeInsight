#include <iostream>
#include <cstdio>
#include <cmath>
#include <cfloat>
#include <ctgmath>

const int D_1 = 0;
const int D_2 = 1;
const int D_3 = 2;
const int D_INF = 3;

const int N = 100;
const int X = 0;
const int Y = 1;

int main(void) {
  int n = 0;
  double data[N][2] = {0};

  std::cin >> n;

  double sumD1 = 0.0;
  double sumD2 = 0.0;
  double sumD3 = 0.0;
  double sumDInf = DBL_MIN;

  for (int i = 0; i < n; i++) {
    std::cin >> data[i][X];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> data[i][Y];
  }  

  for (int i = 0; i < n; i++) {
    double x = data[i][X];
    double y = data[i][Y];    

    double d = std::abs(x - y);

    sumD1 += d;
    sumD2 += std::pow(d, 2.0);
    sumD3 += std::pow(d, 3.0);

    if (d > sumDInf) {
      sumDInf = d;
    }
  }

  double d1 = sumD1;
  double d2 = std::sqrt(sumD2);
  double d3 = std::cbrt(sumD3);;
  double dInf = sumDInf;

  printf("%f\n", d1);
  printf("%f\n", d2);
  printf("%f\n", d3);
  printf("%f\n", dInf);  

  return 0;
}