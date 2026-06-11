#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int A, B, M;
  cin >> A >> B >> M;

  vector<int> a(A);
  vector<int> b(B);
  int min_a = INT_MAX;
  int min_b = INT_MAX;
  rep(i, A) {
    cin >> a[i];
    min_a = min(min_a, a[i]);
  }
  rep(i, B) {
    cin >> b[i];
    min_b = min(min_b, b[i]);
  }

  int ans = min_a + min_b;
  rep(i, M) {
    int x, y, c;
    cin >> x >> y >> c;
    ans = min(ans, a[x - 1] + b[y - 1] - c);
  }
  cout << ans << endl;
  return 0;
}