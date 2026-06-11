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

  int n, a, b, c, d;
  string s;
  cin >> n >> a >> b >> c >> d >> s;
  a--,b--,c--,d--;

  rep(i, a, c+1) {
    if (s[i - 1] == '#' && s[i] == '#') {
      cout << "No" << endl;
      return 0;
    }
  }
  rep(i, b, d+1) {
    if (s[i - 1] == '#' && s[i] == '#') {
      cout << "No" << endl;
      return 0;
    }
  }

  if (c < d) {
    cout << "Yes" << endl;
  } else {
    rep(i, b - 1, d) {
      if (s[i] == '.' && s[i + 1] == '.' && s[i + 2] == '.') {
        cout << "Yes" << endl;
        return 0;
      }
    }
    cout << "No" << endl;
  }
}
