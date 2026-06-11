#include <iostream>
using namespace std;

bool is_frame(int i, int j, int h, int w) {
  return (i == 0 || i == h-1 ||
          j == 0 || j == w-1);
}

  int main() {
  int h, w;
  while (true) {
    cin >> h >> w;
    if (h == 0 && w == 0) return 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++)
        cout << (is_frame(i, j, h, w) ? '#' : '.');
      cout << endl;
    }
    cout << endl;
  }
}