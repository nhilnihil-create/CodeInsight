#include <iostream>
using namespace std;

bool is_sharp(int i, int j) {
  return ((i + j) % 2 == 0);
}

int main() {
  int h, w;
  while (true) {
    cin >> h >> w;
    if (h == 0 && w == 0) return 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++)
        cout << (is_sharp(i, j) ? '#' : '.');
      cout << endl;
    }
    cout << endl;
  }
}