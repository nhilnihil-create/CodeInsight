#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll ans = 1000;

  for (int i = 0; i < n - 1; i++) {
    if (a[i + 1] - a[i] > 0) {
      ll temp = ans / a[i];  //枚数
      ans -= a[i] * temp;

      ans += temp * a[i + 1];
    }
  }

  cout << ans << endl;
}