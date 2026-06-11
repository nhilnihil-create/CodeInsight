#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, Y;
  cin >> X >> Y;
  if (Y % 2 == 1) {
    cout << "No" << endl;
  } else {
    if (Y % 4 == 0) {
      if (Y/4 <= X && X <= Y/2) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    } else {
      if ((Y-2)/4 + 1 <= X && X <= Y/2) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
}