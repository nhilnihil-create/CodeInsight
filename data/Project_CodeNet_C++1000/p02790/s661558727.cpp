#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  int kaunto = 0;
  cin >> a >> b;
  for (int i = 0; i < 10000000; i++) {
    if (a < b) {
      cout << a;
      kaunto++;
      if (kaunto >= b) {
        break;
      }
    }
    if (a > b) {
      cout << b;
      kaunto++;
      if (kaunto >= a) {
        break;
      }
    }
    if (a == b) {
      cout << a;
      kaunto++;
      if (kaunto >= a) {
        break;
      }
    }
  }
}
      