#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int A, B;
  cin >> B >> A;
  int C = 10 * A;
  int D = (25 * B + 1) / 2;
  int ans = max(C, D);
  if (ans / 10 != A) {
    cout << "-1" << endl;
  }
  else if ((2 * ans) / 25 != B) {
    cout << "-1" << endl;
  }
  else {
    cout << ans << endl;
  }
}