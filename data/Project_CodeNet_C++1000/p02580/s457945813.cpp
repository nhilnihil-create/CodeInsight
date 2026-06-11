#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF=1e9;

int main() {
  int h,w,n;
  cin >> h >> w >> n;
  vector<int> hs(h),ws(w);
  set<P> se;
  rep(i,n) {
    int p,q;
    cin >> p >> q;
    --p, --q;
    hs[p]++;
    ws[q]++;
    se.emplace(p,q);
  }
  int mh=0, mw=0;
  rep(i,h) mh = max(mh, hs[i]);
  rep(j,w) mw = max(mw, ws[j]);
  vector<int> is,js;
  rep(i,h) if(hs[i]==mh) is.push_back(i);
  rep(j,w) if(ws[j]==mw) js.push_back(j);
  int ans = mh + mw;
  for (int i : is) for (int j : js) {
    if (se.count(P(i,j))) continue;
    cout << ans << endl;
    return 0;
  }
  cout << ans-1 << endl;
  return 0;
}