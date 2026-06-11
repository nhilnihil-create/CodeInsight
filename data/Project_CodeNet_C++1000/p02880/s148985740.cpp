#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  string ans = "No";
  rep(i, 9) {
    rep(j, 9) {
      if ((i+1)*(j+1) == n) ans = "Yes";
    }
  }
  cout << ans << endl;
}