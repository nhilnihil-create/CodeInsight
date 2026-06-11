#include <iostream>
using namespace std;
typedef long long ll;
int n, m, k;
ll a[200001], b[200001]; // 累積和を格納する

void solve() {
  int ans = 0;
  int j = m;
  // aを先頭から見ていく
  for (int i = 0; i <= n; i++) {
    // aだけでkを超えたら満たせないのでbreak
    if (a[i] > k) break;
    // bを後ろからみる
    while (b[j] + a[i] > k) {
      j--;
    }
    ans = max(ans, i + j);
  
  }
  printf("%d\n", ans);
}

int main() {
  cin >> n >> m >> k;
  // 累積和のため先頭に0を追加
  a[0] = 0;
  b[0] = 0;
  for (int i = 1; i < n + 1; i++) {
    cin >> a[i];
    a[i] += a[i-1];
  }
  for (int i = 1; i < m + 1; i++) {
    cin >> b[i];
    b[i] += b[i-1];
  }
  
  solve();
}