#include <bits/stdc++.h>
using namespace std;

int main() {
  int K, X;
  cin >> K >> X;
  for (int i = X - K + 1; i < X + K; i++) {
    if (i == X + K - 1) cout << i << endl;
    else cout << i << " ";
  }
  return 0;
}
