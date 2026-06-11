#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

struct UnionFind {
  vector<ll> p;
  vector<ll> rank;

  UnionFind(ll n) {
    p.resize(n);
    rank.resize(n, 0);
    for (long long i = 0; i < n; i++) {
      p.at(i) = i;
    }
  }

  ll root(ll x) {
    if (p.at(x) == x) {
      return p.at(x);
    }
    return p.at(x) = root(p.at(x));
  }

  void unite(ll x, ll y) {
    x = root(x);
    y = root(y);
    if (x == y) return;

    if (rank.at(x) > rank.at(y)) {
      swap(x, y);
    }
    if (rank.at(x) == rank.at(y)) {
      rank.at(y)++;
    }
    p.at(x) = p.at(y);
    return;
  }

  bool same(ll x, ll y) { return root(x) == root(y); }
};

int main() {
  ll n, m;
  cin >> n >> m;

  UnionFind uf(n);

  for (long long i = 0; i < m; i++) {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    uf.unite(a, b);
  }

  vector<ll> r(n, 0);
  for (long long i = 0; i < n; i++) {
    r.at(uf.root(i))++;
  }
  sort(r.begin(), r.end());
  reverse(r.begin(), r.end());
  cout << r.front() << endl;
}
