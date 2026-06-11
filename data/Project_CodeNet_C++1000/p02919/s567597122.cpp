#include<bits/stdc++.h>
using namespace std;

using LL = long long;

vector<vector<int>> next(const auto& P, const auto& I, auto end) {
  vector<vector<int>> res(P.size());
  set<int> S;
  for(auto p: P) {
    set<int> remove;
    for(auto x: S) {
      if(p < x) break;
      res[x].emplace_back(I[p]);
      if(res[x].size() == 2) remove.emplace(x);
    }
    for(auto x: remove) S.erase(x);
    S.emplace(p);
  }
  for(auto& x: res) while(x.size() != 2) x.emplace_back(end);
  return res;
}

int main() {
  int N;
  cin >> N;
  vector<int> P(N), I(N);
  for(auto i = 0; i < N; ++i) {
    cin >> P[i];
    I[--P[i]] = i;
  }

  auto R = next(P, I, N);
  reverse(begin(P), end(P));
  auto L = next(P, I, -1);

  LL ans = 0;
  for(auto x = 0; x < N; ++x) {
    LL l1 = I[x]    - L[x][0];
    LL l2 = L[x][0] - L[x][1];
    LL r1 = R[x][0] - I[x];
    LL r2 = R[x][1] - R[x][0];
    ans += (x + 1) * (l1 * r2 + l2 * r1);
  }
  cout << ans << endl;
}
