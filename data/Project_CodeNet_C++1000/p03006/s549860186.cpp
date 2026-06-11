#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) { std::cout << #a << " = " << a << "\n"; }
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }
template<class T, class V> istream& operator>> (istream& ist, pair<T, V>& p) { return ist >> p.first >> p.second; }
template<class T> ostream& operator<< (ostream& ost, pair<T, T>& p) { return ost << p.first << ", " << p.second; }
template<class T> istream& operator>> (istream& ist, vector<T>& vs) { for(auto& e: vs) ist >> e; return ist; }

typedef long long ll;
int const inf = INT_MAX / 2;

namespace tree {
struct union_find {
  vector<int> par, rank, size;
  int compnum;

  union_find(int N) {
    compnum = N;
    par.resize(N), rank.resize(N), size.resize(N);
    for(int i=0; i<N; i++) {
      par[i] = i;
      rank[i] = 0;
      size[i] = 1;
    }
  }

  int root(int x) {
    return par[x] == x ? x : par[x] = root(par[x]);
  }

  void unite(int x, int y) {
    x = root(x), y = root(y);
    if(x == y) return;
    if(rank[x] < rank[y]) {
      par[x] = y, size[y] += size[x];
    } else {
      par[y] = x, size[x] += size[y];
      if(rank[x] == rank[y]) rank[x]++;
    }
    compnum--;
  }

  int operator[](int x) { return root(x); }
  void operator()(int x, int y) { return unite(x, y); }

  bool same(int x, int y) { return root(x) == root(y); }
  int size_of(int x) { return size[root(x)]; }
  int num_of_comps() { return compnum; }
};
}

int main() {
  int N; cin >> N;
  vector<int> x(N), y(N);
  rep(i, N) cin >> x[i] >> y[i];
  map<pair<int, int>, int> mp;
  rep(i, N) {
    mp.emplace(make_pair(x[i], y[i]), i);
  }
  set<pair<int, int>> pqs;
  rep(i, N) REP(j, i + 1, N) {
    auto p = x[i] - x[j], q = y[i] - y[j];
    pqs.emplace(p, q);
    pqs.emplace(-p, -q);
  }
  int ans = inf;
  for (auto pq: pqs) {
    auto p = pq.first, q = pq.second;
    tree::union_find uf(N);
    rep(i, N) {
      auto s = make_pair(x[i], y[i]);
      auto t = make_pair(x[i] - p, y[i] - q);
      if (mp.find(t) == mp.end()) { continue; }
      uf.unite(mp[s], mp[t]);
    }
    ans = min(ans, uf.num_of_comps());
  }
  if (ans == inf) {
    cout << "1\n";
  } else {
    cout << ans << "\n";
  }
}
