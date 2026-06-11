#include<bits/stdc++.h>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  struct Data {int A, B;};
  vector<Data> D(N);
  for(auto& i: D) cin >> i.A >> i.B;
  sort(begin(D), end(D), [&](auto l, auto r) {return l.A < r.A;});
  queue<Data> q;
  for(auto& i: D) q.emplace(i);
  int ans = 0;
  multiset<int, greater<int>> S;
  for(auto i=1; i<=M; ++i) {
    while(!q.empty() && q.front().A<=i) {
      S.emplace(q.front().B);
      q.pop();
    }
    if(S.empty()) continue;
    ans += *begin(S);
    S.erase(begin(S));
  }
  cout << ans << endl;
}
