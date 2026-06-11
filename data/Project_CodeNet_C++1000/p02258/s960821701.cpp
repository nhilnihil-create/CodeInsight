#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int n, minv, maxv, e;
  int count = 0;
  cin >> n;

  maxv = -pow(10, 9);
  cin >> minv;
  for (int i = 1; i < n; i++) {
    cin >> e;
    maxv = max(maxv, e - minv);
    minv = min(minv, e);
  }
  cout << maxv << endl;

  return 0;
}