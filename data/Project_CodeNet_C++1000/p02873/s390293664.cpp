#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  if (s.front() == '>') s = '<' + s;
  if (s.back() == '<') s += '>';

  vector<ll> v;  // <の個数, >の個数, <の個数...
  int cnt = 0;
  bool ku = true;
  for (int i = 0; i < s.size(); i++) {
    if (ku) {
      if (s[i] == '<') {
        cnt++;
      } else {
        v.push_back(cnt);
        cnt = 1;
        ku = false;
      }
    } else {
      if (s[i] == '>') {
        cnt++;
      } else {
        v.push_back(cnt);
        cnt = 1;
        ku = true;
      }
    }
  }
  v.push_back(cnt);

  ll ans = 0;
  ku = true;
  ll mx = 0;
  for (auto w : v) {
    if (ku) {
      // < の個数から解析
      // 最後の < の左側まで確定 (0 < 1 < 2 < ? > >...)
      // それ以外は 0 から昇順
      ans += w * (w - 1) / 2;
      mx = w;
      ku = false;
    } else {
      // > の個数から解析
      // 最初の > の左側は、両側よりも大きい値 ( < 5 < 6 > 2 > 1 > 0 < 1 <...)
      // それ以外は 0 まで降順
      ans += w * (w - 1) / 2;
      ans += max(mx, w);
      ku = true;
    }
  }

  cout << ans << endl;
}