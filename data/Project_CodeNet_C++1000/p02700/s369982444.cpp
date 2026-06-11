#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  string ans;
  while(A > 0 && C > 0) {
    C -= B;
    if (C <= 0) {
      ans = "Yes";
      break;
    }
    A -= D;
    if (A <= 0) {
      ans = "No";
      break;
    }
  }
  cout << ans << endl;
}