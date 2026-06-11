#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y;
  bool ans = false;
  cin >> x >> y;

  for (int crane = 0; crane <= x; crane++) {
    int turtle = x - crane;
    int sum = crane * 2 + turtle * 4;
    if (sum == y) ans = true;
  }
  if (ans) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }  
}