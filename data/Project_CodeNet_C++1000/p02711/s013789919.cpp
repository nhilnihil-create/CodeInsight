#include <bits/stdc++.h>
using namespace std;
int main() {
  string N;
  cin >> N;
  bool b = false;
  for (int i = 0; i < N.size(); i++) {
    if (N.at(i) == '7') {
      b = true;
      break;
    }
  }
  if (b) {cout << "Yes" << endl;}
  else {cout << "No" << endl;}
}