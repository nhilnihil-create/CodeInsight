#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k, s;
  cin >> n >> k >> s;
  vector<ll> a(n);

  rep(i, n) {
    if (i < k)
      a[i] = s;
    else if (s < 1e9)
      a[i] = s + 1;
    else
      a[i] = 1;
  }

  rep(i, n) {
    cout << a[i];
    if (i == n - 1)
      cout << endl;
    else
      cout << ' ';
  }
  return 0;
}
