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

  string s;
  cin >> s;
  deque<char> dq;
  int n = s.size();
  rep(i, 0, n) { dq.push_back(s[i]); }

  bool dir = true;
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      dir = !dir;
    } else {
      int f;
      char c;
      cin >> f >> c;

      if (dir) {
        if (f == 1)
          dq.push_front(c);
        else
          dq.push_back(c);
      } else {
        if (f == 1)
          dq.push_back(c);
        else
          dq.push_front(c);
      }
    }
  }

  if (!dir)
    reverse(dq.begin(), dq.end());
  for (auto d : dq) {
    cout << d;
  }
  cout << endl;
}
