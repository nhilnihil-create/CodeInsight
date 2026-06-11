#include <bits/stdc++.h>
using namespace std;

int main() {

  int X;
  cin >> X;

  int ans = 0;
  int current = 0;
  bool flg = false;

  while (!flg) {
    ans++;
    current += X;
    if (current % 360 == 0) {
      flg = true;
    }
  }

  cout << ans << endl;
  
  return 0;

}