#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
  for(int i = 2; i <= floor(sqrt(x)); i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int X;
  cin >> X;

  while(true) {
    if (isPrime(X)) {
      cout << X << endl;
      return 0;
    }
    X++;
  }
}