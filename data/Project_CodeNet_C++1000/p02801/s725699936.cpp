#include <bits/stdc++.h>
using namespace std;

int main() {
  char C;
  cin >> C;
  string S = "abcdefghijklmnopqrstuvwxyz";
  for (int i = 0; i < 25; i++) {
    if (C == S.at(i)) {
      cout << S.at(i + 1) << endl;
      break;
    }
  }
}