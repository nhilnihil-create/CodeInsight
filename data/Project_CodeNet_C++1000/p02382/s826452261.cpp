#include <iostream>
#include <math.h>
#include <cstdlib>

#define el endl
#define fd fixed

using namespace std;

double min1(int x[], int y[], int n) {
  double res = 0;
  for (int i = 0; i < n; i++)
    res += abs(x[i]-y[i]);
  return res;
}

double min2(int x[], int y[], int n) {
  double res = 0;
  for (int i = 0; i < n; i++)
    res += pow(abs(x[i]-y[i]), 2);
  return pow(res, 1.0/2.0);
}

double min3(int x[], int y[], int n) {
  double res = 0;
  for (int i = 0; i < n; i++)
    res += pow(abs(x[i]-y[i]), 3);
  return pow(res, 1.0/3.0);
}

double mininf(int x[], int y[], int n) {
  double res = 0;
  for (int i = 0; i < n; i++)
    if (res < abs(x[i]-y[i]))
      res = abs(x[i]-y[i]);
  return res;
}

int main() {
  int n;
  cin >> n;
  int x[n], y[n];
  for (int i = 0; i < n; i++)
    cin >> x[i];
  for (int i = 0; i < n; i++)
    cin >> y[i];
  cout << fd << min1(x, y, n) << el << fd << min2(x, y, n) << el << fd << min3(x, y, n) << el << fd << mininf(x, y, n) << el;
  return 0;
}