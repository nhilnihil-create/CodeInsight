#include <bits/stdc++.h>
using namespace std;

int main() {
  long A, V, B, W, T;
  cin >> A >> V >> B >> W >> T;
  long dis = abs(A - B);
  long sp = V - W;
  cout << ((sp * T >= dis) ? "YES" : "NO") << "\n";
}