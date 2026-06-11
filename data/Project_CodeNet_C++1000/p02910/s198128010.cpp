#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  string ans = "Yes";
  for (int i = 0; i < S.size(); i++) {
    if (i == 0) {
      if (S.at(i) == 'L') {
        ans = "No";
      }
    }
    else if (i % 2 == 0 && S.at(i) == 'L') {
      ans = "No";
    }
    else if (i % 2 != 0 && S.at(i) == 'R') {
      ans = "No";
    }
  }
  cout << ans << endl;
}
