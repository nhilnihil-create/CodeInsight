#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;

const int N = (int) 1e5 + 7;
int n;
ll a[N];
ll b[N];
ll suf[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = n; i >= 1; i--) {
    suf[i] = suf[i + 1] + a[i];
  }
  if (n == 0) {
    if (a[0] == 1) {
      cout << "1\n";
    } else {
      cout << "-1\n";
    }
    return 0;
  }
  if (a[0] != 0) {
    cout << "-1\n";
    return 0;
  }
  b[0] = 1;
  for (int i = 1; i <= n; i++) {
    ll lim = min(2 * b[i - 1] - a[i], suf[i + 1]);
    if (lim < b[i - 1] - a[i] || lim < 0) {
      cout << "-1\n";
      return 0;
    }
    b[i] = lim;
  }
  ll sol = 0;
  for (int i = 0; i <= n; i++) {
    sol += a[i] + b[i];
  }
  cout << sol << "\n";
  return 0;
}
