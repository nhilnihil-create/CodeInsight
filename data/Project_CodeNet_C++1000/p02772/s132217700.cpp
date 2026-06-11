#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  string ans = "APPROVED";
  rep(i, n) {
    int x;
    cin >> x;
    if (x % 2 == 0) {
      if (x % 3 != 0 && x % 5 != 0) ans = "DENIED";
    }
  }
  cout << ans << endl;
  return 0;
}