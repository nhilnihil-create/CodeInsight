#include <cmath>
#include <iostream>
using namespace std;
 
double distance(double x[], double y[], int size, int p) {
  int i;
  double res = 0, t;
 
  if (p == -1) {
    for (i = 0; i < size; i++) {
      t = abs(x[i] - y[i]);
      if (t > res) {
        res = t;
      }
    }
 
    return res;
  }
 
  for (i = 0; i < size; i++) {
    res += pow(abs(x[i] - y[i]), p);
  }
 
  return pow(res, 1.0 / p);
}
 
int main() {
  double x[100], y[100];
  int n, i;
 
  cin >> n;
 
  for (i = 0; i < n; i++) {
    cin >> x[i];
  }
 
  for (i = 0; i < n; i++) {
    cin >> y[i];
  }
 
  cout << fixed << distance(x, y, n, 1) << endl;
  cout << fixed << distance(x, y, n, 2) << endl;
  cout << fixed << distance(x, y, n, 3) << endl;
  cout << fixed << distance(x, y, n, -1) << endl;
 
  return 0;
}