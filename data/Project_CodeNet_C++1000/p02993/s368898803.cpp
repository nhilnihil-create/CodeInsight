#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  bool b = true;
  for (int i = 0; i < 3; i++) {
    if (S.at(i) == S.at(i + 1)) {b = false;}
  }
  if (b) {cout << "Good" << endl;}
  else {cout << "Bad" << endl;}
}