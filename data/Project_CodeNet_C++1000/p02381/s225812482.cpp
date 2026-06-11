#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
  while (true) {
    int n;
    cin >> n;
    if (n == 0)
      break;
    double s[1000], a = 0, m = 0;
    for (int i=0;i<n;i++) {
      cin >> s[i];
      m += s[i];
    }
    m /= n;
    for (int i=0;i<n;i++)
      a += pow(s[i] - m, 2);
    a /= n;
    a = pow(a, 0.5);
    cout << fixed << setprecision(10) << a << endl;
  }
}

