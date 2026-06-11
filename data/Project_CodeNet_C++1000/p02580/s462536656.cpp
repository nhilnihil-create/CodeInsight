#include <bits/stdc++.h>
using namespace std;
template<class C>constexpr int sz(const C&c){return int(c.size());}
using ll=long long;constexpr const char nl='\n',sp=' ';

template <class C> struct SegmentTreeBottomUp {
  using Data = typename C::Data; using Lazy = typename C::Lazy;
  int N; vector<Data> TR;
  template <class F> SegmentTreeBottomUp(int N, F f)
      : N(N), TR(N * 2, C::qdef()) {
    generate(TR.begin() + N, TR.end(), f);
    for (int i = N - 1; i > 0; i--) TR[i] = C::merge(TR[i * 2], TR[i * 2 + 1]);
  }
  template <class It> SegmentTreeBottomUp(It st, It en)
      : SegmentTreeBottomUp(en - st, [&] { return *st++; }) {}
  SegmentTreeBottomUp(int N, const Data &vdef)
      : SegmentTreeBottomUp(N, [&] { return vdef; }) {}
  void update(int i, const Lazy &v) {
    for (i += N, TR[i] = C::applyLazy(TR[i], v); i /= 2;)
      TR[i] = C::merge(TR[i * 2], TR[i * 2 + 1]);
  }
  Data query(int l, int r) {
    Data ql = C::qdef(), qr = C::qdef();
    for (l += N, r += N; l <= r; l /= 2, r /= 2) {
      if (l % 2) ql = C::merge(ql, TR[l++]);
      if (!(r % 2)) qr = C::merge(TR[r--], qr);
    }
    return C::merge(ql, qr);
  }
};

struct C {
  using Data = int;
  using Lazy = int;
  static Data qdef() { return numeric_limits<int>::min(); }
  static Data merge(const Data &l, const Data &r) {
    return max(l, r);
  }
  static Data applyLazy(const Data &l, const Lazy &r) {
    return l + r;
  }
};

int main() {
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  // freopen("err.txt", "w", stderr);
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int H, W, M;
  cin >> H >> W >> M;
  vector<vector<int>> ws(H);
  vector<int> wCnt(W, 0);
  for (int i = 0; i < M; i++) {
    int h, w;
    cin >> h >> w;
    ws[--h].push_back(--w);
    wCnt[w]++;
  }
  SegmentTreeBottomUp<C> ST(wCnt.begin(), wCnt.end());
  int ans = 0;
  for (int h = 0; h < H; h++) {
    for (int w : ws[h]) ST.update(w, -1);
    ans = max(ans, sz(ws[h]) + ST.query(0, W - 1));
    for (int w : ws[h]) ST.update(w, 1);
  }
  cout << ans << nl;
  return 0;
}
