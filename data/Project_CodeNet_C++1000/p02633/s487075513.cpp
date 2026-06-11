#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, K;
  cin >> X;
  K = 0;
  
  for (int i = 1; ; i++) {
    if  ((i * X) % 360 == 0) {
      K++;
      break;
    }
    K++;
  }
  cout << K << endl;
  return 0;
}