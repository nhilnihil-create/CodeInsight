#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;

int main() {
    int h, w, m;
    cin >> h >> w >> m;
    vector<int> hs(h), ws(w);
    set<P> s;
    rep(i,m) {
      int r, c;
      cin >> r >> c;
      r--; c--;
      hs[r]++; 
      ws[c]++;
      s.emplace(r,c);
    }
    int mh = 0, mw = 0;
    rep(i,h) mh = max(mh, hs[i]);
    rep(i,w) mw = max(mw, ws[i]);
    vector<int> is, js;
    rep(i,h) if (mh == hs[i]) is.push_back(i);
    rep(i,w) if (mw == ws[i]) js.push_back(i);
    int ans = mh+mw;
    for (int i : is) {
      for (int j : js) {
        if (s.count(P(i,j))) continue;
        cout << ans << endl;
        return 0;
      }
    }
    ans--;
    cout << ans << endl;
    return 0;
}