#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string S;
  cin >> S;

  bool ans = false;
  for (int i = 0; i < S.size(); ++i) {
    if (i % 2 == 0) {
      if (S.at(i) == 'R' || S.at(i) == 'U' || S.at(i) == 'D') {
        ans = true;
      }
      else {
        ans = false;
        cout << "No" << endl;
        break;
      }
    }
    else {
      if (S.at(i) == 'L' || S.at(i) == 'U' || S.at(i) == 'D') {
        ans = true;
      }
      else {
        ans = false;
        cout << "No" << endl;
        break;
      }
    }
  }

  if (ans) {
    cout << "Yes" << endl;
  }
  return 0;
}
