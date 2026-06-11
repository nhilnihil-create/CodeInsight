#include <bits/stdc++.h>

using namespace std;

const int md = (int) 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> f(n + 1);
  f[0] = 1;
  for (int i = 3; i <= n; i++) {
    for (int j = 3; j <= i; j++) {
      (f[i] += f[i - j]) %= md;
    }
  }
  cout << f[n] << endl;
  return 0;
}
