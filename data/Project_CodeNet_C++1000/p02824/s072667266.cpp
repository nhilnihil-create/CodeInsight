#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    int n, m, v, p;
    cin >> n >> m >> v >> p;
    vector<int> a(n);
    for (auto &i:a) {
        cin >> i;
    }
    sort(begin(a), end(a));
    reverse(begin(a), end(a));
    vector<ll> pref(n);
    pref[0] = a[0];
    for (int i = 1; i < n; ++i) {
        pref[i] = pref[i - 1] + a[i];
    }
    auto check = [&](int pos) {
      if (pos < p) {
          return true;
      }
      if (a[pos] + m < a[p - 1]) {
          return false;
      }
      ll sum;
      if (p == 1) {
          sum = pref[pos - 1];
      } else {
          sum = pref[pos - 1] - pref[p - 2];
      }
      return 1ll * (a[pos] + m) * (pos - p + 1) >= sum + 1ll * m * (v - (p + n - 1 - pos));
    };
    int left = 0, right = n - 1;
    while (left != right) {
        int mid = (left + right + 1) / 2;
        if (check(mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    cout << left + 1;
    return 0;
}
