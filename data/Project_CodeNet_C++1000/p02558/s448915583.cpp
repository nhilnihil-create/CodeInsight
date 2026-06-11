#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define l_l pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

struct UnionFind {
  vector<ll> data;

  UnionFind(ll sz) { data.assign(sz, -1); }

  bool unite(ll x, ll y) {
    x = find(x), y = find(y);
    if (x == y) return (false);
    if (data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  ll find(ll k) {
    if (data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  ll size(ll k) { return (-data[find(k)]); }

  bool same(ll x, ll y) {
    int rx = find(x);
    int ry = find(y);
    return rx == ry;
  }
};

int main() {
  // std::cout << std::fixed << std::setprecision(10);

  auto uf = UnionFind(200010);

  ll N, Q;
  scanf("%lld %lld", &N, &Q);

  for (ll i = 0; i < Q; i++) {
    ll t, u, v;
    scanf("%lld %lld %lld", &t, &u, &v);

    if (t == 0) {
      uf.unite(u, v);
    }
    if (t == 1) {
      cout << (uf.same(u, v)) << endl;
    }
  }
}
