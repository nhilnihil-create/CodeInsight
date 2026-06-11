#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> L(N + 1), D(N + 1);
  D.at(0) = 0;
  L.at(0) = 0;
  int ans = 1;
  for (int i = 1; i <= N; i++) {
    cin >> L.at(i);
    D.at(i) = D.at(i - 1) + L.at(i);
    if (D.at(i) <= X) {
      ans++;
    }
    else {
      break;
    }
  }
  cout << ans << endl;
}