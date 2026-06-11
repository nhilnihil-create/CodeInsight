#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, M;
  cin >> A >> B >> M;
  vector<int> a(A), b(B), x(M), y(M), c(M);
  for (int i = 0; i < A; i++) cin >> a.at(i);
  for (int i = 0; i < B; i++) cin >> b.at(i);
  for (int i = 0; i < M; i++) cin >> x.at(i) >> y.at(i) >> c.at(i);
  for (int i = 0; i < M; i++) {
    x.at(i)--;
    y.at(i)--;
  }
  
  int ma = 1000000, mb = 1000000;
  for (int i = 0; i < A; i++) ma = min(ma, a.at(i));
  for (int i = 0; i < B; i++) mb = min(mb, b.at(i));
  
  int ans = ma + mb;
  for (int i = 0; i < M; i++) {
    ans = min(ans, a.at(x.at(i)) + b.at(y.at(i)) - c.at(i));
  }
  cout << ans << endl;
}