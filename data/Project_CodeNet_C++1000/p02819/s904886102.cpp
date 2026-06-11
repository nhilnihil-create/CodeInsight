#include <bits/stdc++.h>
using namespace std;

bool prime(int X) {
  if (X <= 1) return false;
  for (int i = 2; i*i <= X; i++) {
    if (X % i == 0) return false;
  }
  return true;
}

int main(void) {
  int X;
  cin >> X;
  for (int i = 0; ; i++) {
    if (prime(X + i)) {
      cout << X + i << endl;
      return 0;
    }
  }
}