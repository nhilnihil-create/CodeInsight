#include <bits/stdc++.h>

using namespace std;

typedef long long llint;

int main() {
  int n;
  cin >> n;
  vector<llint> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  if (n % 2) {
    llint l = a[n / 2];
    llint r = b[n / 2];
    cout << r - l + 1 << endl;

  } else {
    llint ans = 0;
    if ((a[n / 2 - 1] + a[n / 2]) % 2) {
      ans--;
    }
    if ((b[n / 2 - 1] + b[n / 2]) % 2) {
      ans++;
    }
    llint l = (a[n / 2 - 1] + a[n / 2]) / 2;
    llint r = (b[n / 2 - 1] + b[n / 2]) / 2;
    ans += r - l + 1;
    ans += r - l;
    cout << ans << endl;
  }

  return 0;
}