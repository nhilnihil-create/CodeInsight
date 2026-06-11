#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a;
  int sum(0);
  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;
    sum += a;
  }
  int ans = n - sum;
  if (ans < 0) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}
