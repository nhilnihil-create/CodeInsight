#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  string s;
  cin >> n >> s;
  set<int> rs, gs, bs;
  rep(i, n) {
    switch (s[i]) {
    case 'R':
      rs.insert(i);
      break;
    case 'G':
      gs.insert(i);
      break;
    case 'B':
      bs.insert(i);
      break;
    default:
      break;
    }
  }
  ll ans = 0;
  for (auto ir = rs.begin(); ir != rs.end(); ++ir) {
    for (auto ig = gs.begin(); ig != gs.end(); ++ig) {
      ll now = bs.size();
      int r = *ir;
      int g = *ig;
      if (bs.find(2*r-g) != bs.end()) --now;
      if (bs.find(2*g-r) != bs.end()) --now;
      if ((r+g)%2 == 0 && bs.find((r+g)/2) != bs.end()) --now;
      ans += now;
    }
  }
  cout << ans << endl;
  return 0;
}