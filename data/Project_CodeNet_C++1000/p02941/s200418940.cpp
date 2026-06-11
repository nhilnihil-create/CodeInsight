#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  queue<int> q;
  auto sum = [&](int i) {
    return b[(i + n - 1) % n] + b[(i + n + 1) % n];
  };
  auto canAdd = [&](int i) {
    return b[i] > sum(i) && b[i] > a[i];
  };
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    if (canAdd(i)) {
      q.push(i);
    }
  }
  long long ans = 0;
  while (!q.empty()) {
    int i = q.front();
    q.pop();
    int mod = sum(i);
    int pi = (i + n - 1) % n, ni = (i + n + 1) % n;
    int old = b[i];
    b[i] -= (b[i] - a[i]) / mod * mod;
    ans += (old - b[i]) / mod;
    if (canAdd(pi)) {
      q.push(pi);
    }
    if (canAdd(ni)) {
      q.push(ni);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (b[i] != a[i]) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;
  return 0;
}
