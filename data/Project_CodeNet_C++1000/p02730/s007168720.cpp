#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  bool b = true;
  for (int i = 0; i < S.size() / 2; i++) {
    if (S.at(i) != S.at(S.size() - 1 - i)) {b = false;}
  }
  for (int i = 0; i < S.size() / 2 / 2; i++) {
    if (S.at(i) != S.at(S.size() / 2 - 1 - i)) {b = false;}
  }
  if (b) {cout << "Yes" << endl;}
  else {cout << "No" << endl;}
}