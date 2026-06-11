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

  vector<long long> money(n);
  money[0] = 1000;

  for (int i = 0; i < n - 1; i++) {
    if (a[i] < a[i + 1]) {
      money[i + 1] = money[i] / a[i] * a[i + 1] + money[i] % a[i];
    } else {
      money[i + 1] = money[i];
    }
  }

  cout << money[n - 1] << '\n';

  return 0;
}

