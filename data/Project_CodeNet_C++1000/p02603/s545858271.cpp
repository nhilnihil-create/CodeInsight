#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) {
    cin >> a[i];
  }
  ll stock = 0, money = 1000;
  rep(i, n) {
    if (i == n - 1) {
      money += stock * a[i];
      continue;
    }
    if (a[i + 1] > a[i]) {
      if (stock == 0) {
        stock = money / a[i];
        money = money % a[i];
      }
    } else if (a[i + 1] < a[i]) {
      money += stock * a[i];
      stock = 0;
    }
  }
  cout << money << '\n';
  return 0;
}
