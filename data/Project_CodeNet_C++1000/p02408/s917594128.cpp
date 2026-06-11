#include <iostream>
using namespace std;

int main() {
  int n;
  int a[4][13] = {0};
  char x;
  int y;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    switch (x) {
      case 'S':
        a[0][y - 1] = 1;
        break;
      case 'H':
        a[1][y - 1] = 1;
        break;
      case 'C':
        a[2][y - 1] = 1;
        break;
      case 'D':
        a[3][y - 1] = 1;
        break;
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 13; j++) {
      if (a[i][j] == 0) {
        switch (i) {
          case 0:
            cout << 'S';
            break;
          case 1:
            cout << 'H';
            break;
          case 2:
            cout << 'C';
            break;
          case 3:
            cout << 'D';
            break;
        }
        cout << ' ' << j + 1 << endl;
      }
    }
  }
  return 0;
}