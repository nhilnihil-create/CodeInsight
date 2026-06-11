#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, M = 1e9+7;
  cin >> N;
  long ans = 1;
  vector V(3, 0);
  while (cin >> A) {
    int cnt = 0, j = 0;
    for (int i = 0; i < 3; i++) {
      if (V.at(i) == A) cnt++, j = i;
    }
    ans *= cnt;
    ans %= M;
    V.at(j)++;
  }
  cout << ans << "\n";
}