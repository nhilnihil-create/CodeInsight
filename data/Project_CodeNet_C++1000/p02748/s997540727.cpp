#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, M; 
  cin >> A >> B >> M;
  vector<int> as(A), bs(B); 
  for (auto &a : as) cin >> a; for (auto &b : bs) cin >> b;
  int ans = *min_element(begin(as), end(as)) + *min_element(begin(bs), end(bs));
  while (M--) {
    int x, y, c; cin >> x >> y >> c;
    ans = min(ans, as[--x] + bs[--y] - c);
  }
  cout << ans << endl;
}