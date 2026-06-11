#include<bits/stdc++.h>
using namespace std;

template<typename T> class UnionFind {
 public:
  void unite(const T& a, const T& b) {
    auto x = find(a), y = find(b);
    if(rank_[x] < rank_[y]) std::swap(x, y);
    if(rank_[x] == rank_[y]) ++rank_[x];
    parent_[y] = x;
  }
  T find(const T& x) {
    if(!parent_.count(x)) rank_[x] = 1, parent_[x] = x;
    return (parent_[x] == x) ? x : (parent_[x] = find(parent_[x]));
  }
 private:
  std::map<T, T> parent_;
  std::map<T, int> rank_;
};

template<typename T> class SegmentTree {
 public:
  SegmentTree(int n) : n(size(n)), dat(size(n) << 1), laz(size(n) << 1) {}
  void add(int a, int b, T v) {add(a, b, v, 1, 0, n);}
  T sum(int a, int b) {return sum(a, b, 1, 0, n);}
 private:
  constexpr int size(int n) const {return n & (n - 1) ? size(n + (n & -n)) : n;}
  inline int lchild(int k) const {return (k << 1);}
  inline int rchild(int k) const {return (k << 1) | 1;}
  inline void propagate(int k, int l, int r) {
    if(k < n) {
      laz[lchild(k)] += laz[k];
      laz[rchild(k)] += laz[k];
    }
    dat[k] += (r - l) * laz[k];
    laz[k] = 0;
  }
  T add(int a, int b, T v, int k, int l, int r) {
    propagate(k, l, r);
    if(b <= l || r <= a) return dat[k];
    if(a <= l && r <= b) return dat[k] + (r - l) * (laz[k] = v);
    auto m = (l + r) >> 1;
    auto vl = add(a, b, v, lchild(k), l, m);
    auto vr = add(a, b, v, rchild(k), m, r);
    return dat[k] = vl + vr;
  }
  T sum(int a, int b, int k, int l, int r) {
    propagate(k, l, r);
    if(b <= l || r <= a) return 0;
    if(a <= l && r <= b) return dat[k];
    auto m = (l + r) >> 1;
    auto vl = sum(a, b, lchild(k), l, m);
    auto vr = sum(a, b, rchild(k), m, r);
    return vl + vr;
  }
  int n;
  std::vector<T> dat, laz;
};

using Graph = vector<vector<int>>;

using LL = long long;

int main() {
  int N;
  cin >> N;
  Graph G(N);
  for(auto i=1; i<N; ++i) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  SegmentTree<LL> ST(N);
  UnionFind<int> UF;
  auto n = 0;
  for(auto r=0; r<N; ++r) {
    for(auto v: G[r]) if(v < r) if(UF.find(v) != UF.find(r)) UF.unite(v, r), --n;
    ST.add(r, r+1, ++n);
  }

  LL ans = 0;
  for(auto l=0; l<N; ++l) {
    sort(begin(G[l]), end(G[l]), greater<int>());
    ans += ST.sum(0, N);
    for(auto v: G[l]) if(l < v) ST.add(v, N, 1);
    ST.add(l, N, -1);
  }
  cout << ans << endl;
}
