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

  ll n;
  cin >> n;

  if (n & 1) {
    cout << 0 << endl;
    return 0;
  }

  n /= 2;
  ll k = 5, ans = 0;
  while (n / k) {
    ans += n / k;
    k *= 5;
  }

  cout << ans << endl;
}
