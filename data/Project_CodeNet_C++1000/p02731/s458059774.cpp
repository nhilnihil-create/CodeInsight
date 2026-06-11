#include <iostream>
#include <iomanip>

using namespace std;

int main() {

  int n, ans = 0;
  char inp, old = '#';
  double clay, third;
  cin >> clay;
  third = clay / 3;
  cout << fixed << setprecision(12) << third * third * third;
  return 0;
}
