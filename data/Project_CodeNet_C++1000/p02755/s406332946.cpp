#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B;
  cin >> A >> B;
  bool b = true;
  for(int i = 0; i <= 1000; i++) {
    if(i * 0.08 - A >= 0 && i * 0.08 - A < 1 && i * 0.1 - B >= 0 && i * 0.1 - B < 1) {
      cout << i << endl;
      b = false;
      break;
    }
  }
  if(b) {
    cout << -1 << endl;
  }
}