#include <bits/stdc++.h>
using namespace std;

int gcd(int p, int q) {
  if (p % q == 0) {
    return q;
  }
  return gcd(q, p%q);
}

int main() {
  int N;
  cin >> N;
  int sum = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      for (int k = 1; k <= N; k++) {
        sum += gcd(i, gcd(j, k));
      }
    }
  }
  cout << sum << endl;
}