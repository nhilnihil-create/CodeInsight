#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int X, Y;
  cin >> X >> Y;
  string ans = "No";
  rep(i,X + 1) {
    if(2 * i + 4 * (X - i) == Y) {
      ans = "Yes";
      break;
    }
  }
  cout << ans << endl;
}