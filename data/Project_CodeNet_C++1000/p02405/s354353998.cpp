#include<iostream>
using namespace std;
int main() {
  int h, w, ci;
  string chars[] = {"#", "."};
  while (true) {
    cin >> h >> w;
    if (h == 0 && w == 0) break;
    for (int i = 0; i < h; i++) {
      ci = i % 2;
      for (int j = 0; j < w; j++) {
        cout << chars[ci];
        ci = (ci + 1) % 2;
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}