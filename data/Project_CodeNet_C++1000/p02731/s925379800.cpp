
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)

int main(void) {
  double x;
  cin >> x;
  x /= 3;
  double res = x * x * x;
  printf("%.10f\n", res);
}
