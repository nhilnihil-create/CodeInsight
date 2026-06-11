#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, R;
  cin >> N >> R;

  int X = 0;
  if (N < 10) {
      X = 100 * (10 - N) + R;
  }
  else X = R;
  
  cout << X << endl;
}
