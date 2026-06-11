#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<pair<long long, long long>> stock(n + 1);
  vector<long long> money(n + 1);
  money[0] = 1000;

  for (int i = 0; i < n; i++) {
    money[i + 1] = max(money[i], stock[i].first * a[i] + stock[i].second);
    stock[i + 1] = max(stock[i], {money[i] / a[i], money[i] % a[i]});
  }

  cout << money[n] << '\n';

  return 0;
}

