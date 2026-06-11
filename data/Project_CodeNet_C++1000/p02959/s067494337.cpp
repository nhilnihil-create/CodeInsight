#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n+1, 0), b(n, 0);
  for (int i = 0; i < n+1; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (b[i] == 0) continue;
    
    if (b[i] <= a[i]) {
      ans += b[i];
      continue;
    }

    if (b[i] <= a[i] + a[i+1]) {
      ans += b[i];
      b[i] -= a[i];
      a[i+1] -= b[i];
      continue;
    }
    // Ai, Ai+1を全て倒せる場合
    ans += a[i] + a[i+1];
    a[i+1] = 0;
  }
  cout << ans << endl;
  return 0;
}