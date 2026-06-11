#include <bits/stdc++.h>
using namespace std;

int main() {
  int k, L, sum = 0;
  cin >> k;
  if (k % 2 == 0 || k % 5 == 0) sum = -1;

  else {
    L = 9 * k;
    if (L % 7 == 0) L /= 7;
    
    int i = 10;
    bool jug = true;
    while (jug) {
      sum++;
      i %= L;
      if (i == 1) {
        jug = false;
      }
      i *= 10;
    }
  } 
  cout << sum << endl;
}