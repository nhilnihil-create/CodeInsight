#include <iostream>

using namespace std;

int main() {

  int a, b, c;
  cin >> a >> b;
  cout << (a * b) * ((a < 10 && b< 10)) + !(a < 10 && b< 10) * (-1);
  return 0;
}
