#include <bits/stdc++.h>
using namespace std;

int main() {
  int S, W;
  cin >> S >> W;
  string res;
  if (S <= W) {
    res = "unsafe";
  } else {
    res = "safe";
  }
  cout << res << endl;
}
