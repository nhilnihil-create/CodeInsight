#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double minko(int n, int p, double x[], double y[]) {
  double d = 0.0;
  for (int i=0;i<n;i++)
    d += pow(abs(x[i] - y[i]), p);
  d = pow(d, 1.0 / (double)p);
  return d;
}

double minkomax(int n, double x[], double y[]) {
  double d = 0.0;
  for (int i=0;i<n;i++) {
    double tmp = abs(x[i] - y[i]);
    if (d < tmp)
      d = tmp;
  }
  return d;
}

int main() {
  int n;
  double x[100], y[100];
  cin >> n;
  for (int i=0;i<n;i++)
    cin >> x[i];
  for (int i=0;i<n;i++)
    cin >> y[i];
  
  cout << fixed << setprecision(10)
       << minko(n, 1, x, y) << endl
       << minko(n, 2, x, y) << endl
       << minko(n, 3, x, y) << endl
       << minkomax(n, x, y) << endl;
}

