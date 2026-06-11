#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<P> q, r;
  rep(i,n) {
    int x, y;
    cin >> x >> y;
    q.emplace_back(1e9-x, 1e9-y);
    r.emplace_back(x-1e9, 1e9-y);
  }
  sort(q.begin(), q.end(), [] (P x, P y) {
    return (x.first+x.second) < (y.first+y.second);
  });
  sort(r.begin(), r.end(), [] (P x, P y) {
    return (x.first+x.second) < (y.first+y.second);
  });
  P a = q.back(), b = q.front();
  P c = r.back(), d = r.front();
  cout << max(a.first+a.second-b.first-b.second, c.first+c.second-d.first-d.second) << endl;
}