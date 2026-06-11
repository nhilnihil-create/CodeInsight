#include <iostream>
#include <cmath>
using namespace std;

int main() {
  long double a, b;
  cin >> a >> b;

  cout << 1LL*floor(a*b + 0.001) << '\n';
}
