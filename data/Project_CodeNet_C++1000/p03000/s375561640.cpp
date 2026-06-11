#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, x;
  int sum = 0;

  cin >> n >> x;

  int v, ans = 1;
  for (int i = 0; i < n; i++) {
    cin >> v;
    sum += v;

    if (sum <= x) ans++;
  }

  cout << ans << endl;
  
  return 0;
}
