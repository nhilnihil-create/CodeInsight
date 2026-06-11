#include<bits/stdc++.h>
using namespace std;

using LL = long long;

int main() {
  int N;
  cin >> N;
  vector<int> P(N);
  for(auto& i: P) cin >> i, --i;

  struct Data {LL p, i; vector<LL> l, r;};
  vector<Data> X(N);
  for(auto i = 0; i < N; ++i) X[P[i]].p = P[i] + 1, X[P[i]].i = i;

  set<int> R;
  for(auto p: P) {
    set<int> remove;
    for(auto x: R) {
      if(p < x) break;
      if(X[x].r.size() == 2) remove.emplace(x);
      else                   X[x].r.emplace_back(X[p].i);
    }
    for(auto x: remove) R.erase(x);
    R.emplace(p);
  }
  for(auto& x: X) while(x.r.size() != 2) x.r.emplace_back(N);

  set<int> L;
  reverse(begin(P), end(P));
  for(auto p: P) {
    set<int> remove;
    for(auto x: L) {
      if(p < x) break;
      if(X[x].l.size() == 2) remove.emplace(x);
      else                   X[x].l.emplace_back(X[p].i);
    }
    for(auto x: remove) L.erase(x);
    L.emplace(p);
  }
  for(auto& x: X) while(x.l.size() != 2) x.l.emplace_back(-1);

  LL ans = 0;
  for(auto& x: X) {
    auto l1 = x.i - x.l[0];
    auto l2 = x.l[0] - x.l[1];
    auto r1 = x.r[0] - x.i;
    auto r2 = x.r[1] - x.r[0];
    auto d =  l1 * r2 + l2 * r1;
    ans += x.p * d;
  }
  cout << ans << endl;
}
