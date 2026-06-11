#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  printf("%d %d %f\n", a / b, a % b,
         static_cast<double>(a) / static_cast<double>(b));
  return 0;
}