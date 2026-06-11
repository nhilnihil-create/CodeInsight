#include <iostream>
#include <cmath>
using namespace std;

int main() {
  double n, x, t;
  cin >> n >> x >> t;

  int res = ceil(n/x)*t;
  cout << res << endl;
}