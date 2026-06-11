#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int N, X, Y;
  cin >> N >> X >> Y;
  Graph G(N + 1);
  queue<P> q;
  map<P, int> m;
  vector<int> cnt(N, 0);

  rep(i, N + 1) {
    if (i == 0) continue;
    if (i > 1) G.at(i).push_back(i - 1);
    if (i < N) {
      G.at(i).push_back(i + 1);
      q.push(P(i, i + 1));
      m[P(i, i + 1)] = 1;
      cnt.at(1)++;
    }
  }

  G.at(X).push_back(Y);
  G.at(Y).push_back(X);
  q.push(P(X, Y));
  m[P(X, Y)] = 1;
  cnt.at(1)++;

  while (!q.empty()) {
    auto p = q.front();
    auto d = m.at(p);
    for (auto s : G.at(p.second)) {
      if (p.first >= s) continue;
      if (m.count(P(p.first, s))) continue;
      q.push(P(p.first, s));
      m[P(p.first, s)] = d + 1;
      cnt.at(d + 1)++;
    }
    for (auto f : G.at(p.first)) {
      if (f >= p.second) continue;
      if (m.count(P(f, p.second))) continue;
      q.push(P(f, p.second));
      m[P(f, p.second)] = d + 1;
      cnt.at(d + 1)++;
    }
    q.pop();
  }

  rep(i, N) {
    if (i == 0) continue;
    cout << cnt.at(i) << endl;
  }
}
