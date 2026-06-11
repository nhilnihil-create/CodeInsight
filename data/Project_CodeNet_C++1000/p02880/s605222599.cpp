/**
 *  author: Behradm
 *  Created: 2020.08.02 15:49:42
 *  In The Name Of God
**/
#include <bits/stdc++.h>

using namespace std;

int main() {   
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  if (n > 81) {
    cout << "No\n";
    return 0;
  }

  bool good = false;
  for (int a = 1; a <= 9; a++) {
    for (int b = 1; b <= 9; b++) {
      if (a * b == n) {
        good = true;
        break;
      }
    }
    if (good)
      break;
  }

  cout << (good ? "Yes" : "No") << '\n';
  return 0;
}
