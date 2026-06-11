#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll x;
  cin >> x;

  for (ll a = -150; a <= 150; a++) {
    for (ll b = -150; b <= 150; b++) {
      ll aa = a * a * a * a * a;
      ll bb = b * b * b * b * b;
      if (aa - bb == x) {
        cout << a << " " << b << endl;
        return 0;
      }
    }
  }
}
