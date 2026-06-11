#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i.second<< " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  // bit全探索
  int N;
  cin >> N;
  vector<vector<P>> XY;
  rep(i, N) {
    int A;
    cin >> A;
    vector<P> B;
    rep(j, A) {
      int X, Y;
      cin >> X >> Y;
      --X;
      B.push_back(make_pair(X, Y));
    }
    XY.push_back(B);
  }
  //rep(i, N) show(XY[i]);
  int ans = 0;  
  for (int bit = 0; bit < (1<<N); bit++) {
    bool flag = true;
    for (int i = 0; i < N; i++) {
      if ((bit&(1<<i)) == 0) continue;
      for (auto p : XY[i]) {
        if (((bit>>p.first)&1) ^ (p.second==1)) {
          //cout << bit << '-' << i << '-' << p.first << '\n';
          flag = false; break;
        }
      }
    }
    if (flag) {
      ans = max(ans, __builtin_popcount(bit));
    }
  }
  cout << ans << '\n';
  return 0;
}