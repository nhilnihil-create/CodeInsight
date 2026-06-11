#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<vector<P>> person(n);
  rep(i,0,n) {
    int a;
    cin >> a;
    rep(j,0,a) {
      int x,y;
      cin >> x >> y;
      x--;
      person[i].push_back(P(x,y));
    }
  }
  int ans = 0;
  rep(bit,0,1<<n) {
    bool flag = true;
    int cnt = __builtin_popcount(bit);
    if (ans > cnt) continue;
    vector<bool> ishonest(n,false);
    rep(i,0,n) {
      if ((bit >> i) & 1) ishonest[i] = true;
    }
    rep(i,0,n) {
      if ((bit >> i) & 1) {
        rep(j,0,person[i].size()) {
          int x = person[i][j].first, y = person[i][j].second;
          if (y != ishonest[x]) {
            flag = false;
          }
        }
      }
    }
    if (flag) ans = cnt;
  }
  cout << ans << endl;
  return 0;
}
