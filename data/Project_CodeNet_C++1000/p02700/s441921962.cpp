#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  bool turn = true;
  while(a > 0 && c > 0) {
    if(turn) c -= b;
    else a -= d;
    turn = !turn;
  }
  if(turn) cout << "No" << endl;
  else cout << "Yes" << endl;
}
