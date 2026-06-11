#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, N;
  cin >> X >> N;
  vector<int> bac(1000, 0);
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    bac[a] = 1;
  }
  int mi = 1000, res = -1;
  for (int i = 0; i < 1000; ++i) {
    if (bac[i]) continue;
    if (mi > abs(X - i)) {
      mi = abs(X - i);
      res = i;
    }
  }
  cout << res << endl;
}