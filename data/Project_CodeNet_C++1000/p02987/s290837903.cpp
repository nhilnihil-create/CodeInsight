#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  bool ans = false;
  if(S.at(0) == S.at(1) && S.at(2) == S.at(3) && S.at(0) != S.at(2)) {
    ans = true;
  }
  else if(S.at(0) == S.at(2) && S.at(1) == S.at(3) && S.at(0) != S.at(1)) {
    ans = true;
  }
  else if(S.at(0) == S.at(3) && S.at(1) == S.at(2) && S.at(0) != S.at(1)) {
    ans = true;
  }
  if(ans) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}