#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, V, B, W, T;
  cin >> A >> V >> B >> W >> T;
  if (V - W == 0 || abs(B - A) * 1.0 / (V - W) < 0 ||
      T < abs(B - A) * 1.0 / (V - W)) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}
