#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;
  if (y % 4 != 0 && y % 2 != 0) {
    cout << "No" << endl;
  }
  else {
    if (y >= 2*x && y <= 4*x) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
  }
}