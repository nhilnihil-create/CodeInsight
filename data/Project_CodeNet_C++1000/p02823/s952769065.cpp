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

  ll n, a, b;
  cin >> n >> a >> b;

  if ((b - a) % 2 == 0)
    cout << (b - a) / 2 << endl;
  else {
    ll a1 = min(b - 1, a + (b - a - 1) / 2);
    ll t = n - b + 1;
    ll a2 = min(n - a, t + (n - (a + t)) / 2);
    cout << min(a1, a2) << endl;
  }
}
