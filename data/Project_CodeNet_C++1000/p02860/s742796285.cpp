#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n;
  string s, ans = "Yes";
  cin >> n >> s;
  if(n % 2 != 0) ans = "No";
  else {
    rep(i, n/2) {
      if(s.at(i) != s.at(n/2+i)) ans = "No";
    }
  }
  cout << ans << endl;
}
