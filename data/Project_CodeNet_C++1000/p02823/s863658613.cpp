#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, a, b;
  cin >> n >> a >> b;
  if ((b - a) % 2 == 0) {
    cout << (b - a) / 2;
  } else {
    cout << min({n - a, b - 1, a + (b - a) / 2, n - b + (b - a + 1) / 2});
  }
  return 0;
}
