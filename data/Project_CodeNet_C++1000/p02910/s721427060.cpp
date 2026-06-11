#include <bits/stdc++.h>
using namespace std;
 
int main () {
  string S;
  cin >> S;
  bool ok = true;
  for (int i = 0; i < S.size(); i++) {
    if (i % 2 != 0 && S.at(i) == 'R') {
      ok = false;
      break;
    }
    else if (i % 2 == 0 && S.at(i) == 'L') {
      ok = false;
      break;
    }
  }
  if (ok) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}