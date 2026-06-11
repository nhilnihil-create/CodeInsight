#include <iostream>

using namespace std;

int main() {
  int w, h, x, y;
  cin >> w >> h >> x >> y;
  cout << static_cast<double>(w) * h / 2 << " " << int(w == 2 * x && h == 2 * y) << endl;
}