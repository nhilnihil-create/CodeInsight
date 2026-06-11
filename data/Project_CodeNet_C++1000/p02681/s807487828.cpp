#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string S, T;
  cin >> S >> T;
  string ans;
  if (S.size() + 1 == T.size()) {
    rep(i,S.size()) {
      if (S.at(i) == T.at(i)) ans = "Yes";
      else {
        ans = "No";
        break;
      }
    }
  }
  else ans = "No";
  cout << ans << endl;
}