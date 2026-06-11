# include <iostream>
# include <algorithm>
using namespace std;

int A, B, M;

int main() {
  cin >> A >> B >> M;
  int a[A], b[B];
  for (int i = 0; i < A; ++i) cin >> a[i];
  for (int i = 0; i < B; ++i) cin >> b[i];
  
  int ans = 200000;
  for (int i = 0; i < M; ++i) {
    int x, y, c; cin >> x >> y >> c;
    ans = min(ans, a[x - 1] + b[y - 1] - c);
  }
  
  // 割引券を使わない場合の最小値
  sort(a, a + A);
  sort(b, b + B);
  ans = min(ans, a[0] + b[0]);
  
  cout << ans << endl;
   
  return 0;
}