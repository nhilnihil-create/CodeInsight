#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll A, B, V, W, T;
  cin >> A >> V;
  cin >> B >> W;
  cin >> T;
  if (V > W && abs(A - B) <= T * (V - W)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
