#include <bits/stdc++.h>
using namespace std;

int main() {
  string S, T;
  cin >> S >> T;
  if (S.size() < T.size()) {
    if (S == T.erase(S.size(), 1) ) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  } else {
    cout << "No" << endl;
  }
}