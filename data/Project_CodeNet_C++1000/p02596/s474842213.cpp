#include <bits/stdc++.h>
using namespace std;

int main() {
  int k;
  cin >> k;
  int prev_a = 7 % k;
  if (prev_a == 0) {
    cout << 1 << endl;
  }
  else {    
    bool done = false;
    for (int i = 2; i <= k; ++i) {
      int curr_a = (prev_a*10 + 7) %k;
      if (curr_a == 0) {
        done = true;
        cout << i << endl;
        break;
      }
      else {
        prev_a = curr_a;
      }
    }
    if (!done) {
      cout << -1 << endl;
    }
  }
}