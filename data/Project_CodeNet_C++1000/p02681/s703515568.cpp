#include <bits/stdc++.h>
using namespace std;

int main() {
  string S, T;
  cin >> S;
  cin >> T;
  bool result = true;
  for (int i = 0; i < S.size(); i++) {
    if (S.at(i) != T.at(i)) {
      result = false;
      break;
    }
  }
  if(result) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  return 0;
}