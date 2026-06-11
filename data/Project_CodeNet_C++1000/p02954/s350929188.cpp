#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  int n = s.size();

  vector<int> vr(n, 0), vl(n, 0);
  int c = 1;
  rep(i, 1, n) {
    if (s[i] == 'R')
      c++;
    else {
      vr[i] = c;
      c = 0;
    }
  }

  c = 1;
  repr(i, 0, n - 1) {
    if (s[i] == 'L')
      c++;
    else {
      vl[i] = c;
      c = 0;
    }
  }

  vector<int> ans(n, 0);
  rep(i, 1, n) {
    if (s[i] == 'L' && s[i - 1] == 'R') {
      int r = vr[i], l = vl[i - 1];
      ans[i - 1] = (r + 1) / 2 + l / 2;
      ans[i] = r / 2 + (l + 1) / 2;
      i++;
    }
  }

  rep(i, 0, n) {
    if (i > 0)
      cout << " ";
    cout << ans[i];
  }
  cout << endl;
}
