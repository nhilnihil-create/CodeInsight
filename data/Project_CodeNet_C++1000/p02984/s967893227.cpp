#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i], a[i] *= 2;

  ll o = 0;
  rep(i, 0, n) {
    // test
    o = a[i] - o;
  }
  ll x = o / 2;

  ll now = x;
  rep(i, 0, n) {
    if (i > 0)
      cout << " ";
    cout << now;
    now = a[i] - now;
  }
  cout << endl;
}
