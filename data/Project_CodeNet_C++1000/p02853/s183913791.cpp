#include <iostream>
using namespace std;

int main() {
  short int x, y;
  cin >> x >> y;
  if (x == 1 && y == 1) cout << 400000 + 300000 + 300000 << '\n';
  else {
    int s = 0;
    if (x <= 3) s += (4 - x) * 100000;
    if (y <= 3) s += (4 - y) * 100000;
    cout << s << '\n';
  }
  return 0;
}