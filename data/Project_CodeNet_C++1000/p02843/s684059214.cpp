#include <bits/stdc++.h>
using namespace std;

int main() {
  int x;
  cin >> x;
  
  bool bo = false;
  if (x >= 2100) {
    bo = true;
  }
  else {
    for (int i = 0; i < 20; i++) {
      for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 2; k++) {
          for (int l = 0; l < 2; l++) {
            for (int m = 0; m < 2; m++) {
              if (m * 1 + l * 2 + k * 3 + j * 4 + i * 5 == (x % 100)) {
                if ((i + j + k + l + m) <= x / 100) {
                  bo = true;
                }
              }
            }
          }
        }
      }
    }
  }
  if (bo) {
    cout << 1 << endl;
  }
  else {
    cout << 0 << endl;
  }
}
