#include <iostream>
#include <numeric>

using namespace std;

int main() {
  int X;
  cin >> X;
  cout << 360/gcd(360, X) << endl;
}
