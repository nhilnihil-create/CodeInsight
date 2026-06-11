#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<P> xl(n);
  rep(i, n) {
    int x, l;
    cin >> x >> l;
    xl.at(i) = make_pair(x, l);
  }
  vector<P> ft(n);
  rep(i, n) {
    int x = xl.at(i).first;
    int l = xl.at(i).second;
    ft.at(i) = make_pair(x + l, x - l);
  }
  sort(ft.begin(), ft.end());
  int res = 0;
  int cur = INT_MIN;
  rep(i, n) {
    if (ft.at(i).second >= cur) {
      cur = ft.at(i).first;
      res++;
    }
  }
  cout << res << endl;
  return 0;
}
