#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int n;
  cin >> n;
  double a = floor(n/1.08);
  double b = ceil(n/1.08);
  if (n == (int)floor(a*1.08)) {
    cout << a << endl;
  } else if (n == (int)floor(b*1.08)) {
    cout << b << endl;
  } else {
    cout << ":(" << endl;
  }
}
