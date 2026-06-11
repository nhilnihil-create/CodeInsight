#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  int a, b, h, m;
  cin >> a >> b >> h >> m;
  double rad = abs(M_PI * 2 * (h + double(m) / 60) / 12 - M_PI * 2 * double(m) / 60);
  cout << setprecision(20) << sqrt(a * a + b * b - 2 * a * b * cos(rad)) << endl;
}
