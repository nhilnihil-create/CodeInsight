#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int N;
  cin >> N;
  string S;
  cin >> S;
  bool ok = true;
  if (N % 2 == 1) {
    ok = false;
  }
  else {
    for (int i = 0; i < N / 2; i++) {
      if (S.at(i) != S.at(N / 2 + i)) {
        ok = false;
        break;
      }
    }
  }
  if (ok) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }

}