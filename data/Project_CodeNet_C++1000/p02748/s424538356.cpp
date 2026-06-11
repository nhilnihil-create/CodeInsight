#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, M;
  cin >> A >> B >> M;

  vector<int> a(A), b(B);
  for (int i = 0; i < A; i++) {
    cin >> a.at(i);
  }
  for (int j = 0; j < B; j++) {
    cin >> b.at(j);
  }

  int ans = 200000;
  for (int k = 0; k < M; k++) {
    int x, y, c;
    cin >> x >> y >> c;
    int num = a.at(x-1)+b.at(y-1)-c;
    ans = min(ans, num);
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  ans = min(ans, a.at(0)+b.at(0));

  cout << ans << endl;

}