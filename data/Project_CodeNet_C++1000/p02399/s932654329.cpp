#include <iostream>
using namespace std;

int main() {
  int a, b;

  cin >> a >> b;

  int d = a / b;
  int r = a % b;
  double f = (double)a / (double)b;

  printf("%d %d %.8lf\n", d, r, f);
}
