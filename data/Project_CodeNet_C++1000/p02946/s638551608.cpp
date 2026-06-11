#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int K, X;
  cin >> K >> X;

  for (int i = X - K + 1; i < K + X; i++) {
    cout << i << " ";
  }
  return 0;
}