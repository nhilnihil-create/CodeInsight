#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, M;
  cin >> A >> B >> M;
  vector<int> a(A), b(B);
  for (int i = 0; i < A; i++) {
    cin >> a.at(i);
  }
  for (int i = 0; i < B; i++) {
    cin >> b.at(i);
  }
  int ans = 1000000000;
  for (int i = 0; i < M; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    x--;
    y--;
    ans = min(ans, a.at(x) + b.at(y) - c);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  ans = min(ans, a.at(0) + b.at(0));
  cout << ans << endl;
  return 0;
}
