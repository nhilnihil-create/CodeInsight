#include <bits/stdc++.h>
using namespace std;

int main() {
  int X;
  cin >> X;
  for (int i = 1; i < 1000; i++) {
    if (X * i % 360 == 0) {
      cout << i << endl;
      break;
    }
  }
}