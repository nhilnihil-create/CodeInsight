#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int n;
  for (;;) {
    cin >> n;
    if (n == 0) {
      break;
    }

    int a[1000];
    double m = 0.0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      m += static_cast<double>(a[i]);
    }
    m /= static_cast<double>(n);

    double var = 0.0;
    for (int i = 0; i < n; ++i) {
      var += (static_cast<double>(a[i]) - m) * (static_cast<double>(a[i]) - m);
    }
    var /= static_cast<double>(n);
    printf("%f\n", sqrt(var));
  }
  return 0;
}