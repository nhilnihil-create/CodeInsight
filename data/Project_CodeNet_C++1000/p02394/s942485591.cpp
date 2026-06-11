#include <iostream>

using namespace std;

int main() {
  int W, H, x, y, r;
  cin >> W >> H >> x >> y >> r;

  int a = r;
  int b = W - r;
  int c = r;
  int d = H - r;

  if (x >= a && x <= b && y >= c && y <= d) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
