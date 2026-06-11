#include <bits/stdc++.h>
using namespace std;

int main() {
  int x,y;
  cin >> x >> y;
  bool can = false;
  for (int i = 0; i < x+1; i++) {
    for (int j = 0; j < x+1; j++) {
      if (i * 2 + j * 4 == y && i + j == x) {
        can = true;
      }
    }
  }
  if (can) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
