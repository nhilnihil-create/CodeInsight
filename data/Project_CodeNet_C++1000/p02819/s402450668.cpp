#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long int;

int main() {
  int X;
  cin >> X;

  for (int i = X;; i++) {
    bool is_prime = true;
    for (int j = 2; j < i; j++) {
      if (i % j == 0) {
        is_prime = false;
        break;
      }
    }
    if (is_prime) {
      cout << i << endl;
      return 0;
    }
  }
}