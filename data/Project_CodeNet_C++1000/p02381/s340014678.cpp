#include <iostream>
#include <math.h>

using namespace std;

int main() {
  while (1) {
    int n;
    cin >> n;
    if (n == 0) break;
    int a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];
    double m = 0.0;
    for (int i = 0; i < n; i++)
      m += a[i];
    m /= n;
    double d = 0.0;
    for (int i = 0; i < n; i++)
      d += pow(a[i]-m, 2);
    d /= n;
    cout << fixed << sqrt(d) << endl;
  }
  return 0;
}