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

  int n, m;
  cin >> n >> m;
  int one = -1, two = -1, thr = -1;

  rep(i, 0, m) {
    int s, c;
    cin >> s >> c;
    if (s == 1) {
      if ((one != -1 && one != c) || (n != 1 && c == 0)) {
        cout << -1 << endl;
        return 0;
      }
      one = c;
    } else if (s == 2) {
      if (n < s || (two != -1 && two != c)) {
        cout << -1 << endl;
        return 0;
      }
      two = c;
    } else {
      if (n < s || (thr != -1 && thr != c)) {
        cout << -1 << endl;
        return 0;
      }
      thr = c;
    }
  }

  if (n == 1) {
    cout << max(0, one) << endl;
  } else if (n == 2) {
    if (one != -1)
      cout << one;
    else
      cout << 1;
    if (two != -1)
      cout << two;
    else
      cout << 0;
    cout << endl;
  } else {
    if (one != -1)
      cout << one;
    else
      cout << 1;
    if (two != -1)
      cout << two;
    else
      cout << 0;
    if (thr != -1)
      cout << thr;
    else
      cout << 0;
    cout << endl;
  }
}
