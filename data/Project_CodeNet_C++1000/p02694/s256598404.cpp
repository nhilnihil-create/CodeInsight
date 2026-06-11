#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl

void solve() {
  ll n;
  cin >> n;
  ll p = 100, year = 0;
  while (p < n) {
    p += p / 100;
    year++;
  }
  cout << year << '\n';
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ll test = 1;
  // cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
