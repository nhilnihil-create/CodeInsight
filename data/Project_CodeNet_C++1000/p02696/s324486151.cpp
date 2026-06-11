#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

ll n, a, b;
ll ans = 0;
bool is_ok_binarysearch_number(ll index) {
  ll v = (a * index) / b - a * (index / b);
  if (index <= n) {
    if (v >= ans) {
      ans = v;
      return true;
    } else
      return false;
  } else
    return false;
}

void binarysearch_number() {
  ll ng = 1000000000001;
  ll ok = 0;

  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if (is_ok_binarysearch_number(mid))
      ok = mid;
    else
      ng = mid;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> a >> b >> n;
  binarysearch_number();
  cout << ans << endl;
}
