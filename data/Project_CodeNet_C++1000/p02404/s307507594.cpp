#include<iostream>
using namespace std;
int main() {
  int h, w;
  string c;
  while (true) {
    cin >> h >> w;
    if (h == 0 && w == 0) break;
    for (int i = 0; i < h; i++) {
      cout << "#";
      if (i == 0 || i == h - 1) c = "#";
      else c = ".";
      for (int j = 0; j < w - 2; j++) cout << c;
      cout << "#" << endl;
    }
    cout << endl;
  }
  return 0;
}