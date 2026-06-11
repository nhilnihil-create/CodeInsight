#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t X, K, D;
  cin >> X >> K >> D;
  if (X < 0) X = -X;
  if (X / D < K) {
    K = K - X / D;
    X = X % D;
    if (K % 2 == 0) {
      cout << X << endl;
    } else {
      cout << abs(X-D) << endl;
    }
  } else {
    cout << abs(X - K*D) << endl;
  }
}