#include <bits/stdc++.h>
using namespace std;

int main() {
  int X;
  cin >> X;

  int a = X % 500;
  int b = X / 500;
  int c = a / 5;
  cout << b * 1000 + c * 5 << endl;
  return 0;
}
