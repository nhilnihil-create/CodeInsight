#pragma GCC optimize("Ofast")
#define _USE_MATH_DEFINES
#include "bits/stdc++.h"

using namespace std;

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

constexpr char newl = '\n';
constexpr double eps = 1e-10;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,b) FOR(i,0,b)
#define RFO(i,a,b) for (int i = ((b)-1); i >=(a); i--)
#define RF0(i,b) RFO(i,0,b)
#define fi first
#define se second
#define debug(x) cout << #x << ": " << x << '\n';
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()

template<typename T1, typename T2> inline void chmin(T1& a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
template<class T> void Print(vector<T> v) {
  F0R(i, v.size()) {
    cout << v[i] << ' ';
  }
  cout << newl;
}

#if 1


template<class Element, class Lazy>
class SegmentTree {

  // TODO: std::function は重いらしいのでやめる
  // https://twitter.com/satanic0258/status/1049041099115782144

  using A = function<Element(const Element&, const Element&)>;
  using B = function<void(Element&, const Lazy&, int elementCount)>;
  using C = function<void(Lazy&, const Lazy&)>;

  using ECallback = function<void(const Element&, const Lazy&)>;

  // index -> parent index
  constexpr int parent(int v) {
    return ((v + 1) >> 1) - 1;
  }
  constexpr bool hasChild(int v) {
    return v <= size - 2;
  }
  constexpr int lchild(int v) {
    return ((v + 1) << 1) - 1;
  }
  constexpr int rchild(int v) {
    return (v + 1) << 1;
  }

public:

  /// <summary>
  /// 
  /// </summary>
  /// <param name="size"></param>
  /// <param name="mergeElements">要素2つを結合</param>
  /// <param name="applyLazyToElement">要素に遅延評価分を適用</param>
  /// <param name="mergeLazies">遅延評価2つを結合</param>
  SegmentTree(int size, A mergeElements, B applyLazyToElement, C mergeLazies) :
    mergeTT(mergeElements), mergeTE(applyLazyToElement), mergeEE(mergeLazies) {

    int n = 1;
    while (n < size) n <<= 1;

    this->size = n;

    int segCount = n * 2 - 1;

    es = vector<Element>(segCount);

    ls = vector<Lazy>(segCount);

    lazyFlag = vector<bool>(segCount, false);

    lefts = vector<int>(segCount);
    rights = vector<int>(segCount);
    mp = vector<int>(segCount);

    for (int i = 0, l = 0, w = n; i < segCount; i++) {
      lefts[i] = l;
      rights[i] = lefts[i] + w;
      mp[i] = lefts[i] + (w >> 1);

      if (rights[i] >= n) {
        w >>= 1; l = 0;
      }
      else {
        l += w;
      }
    }
  }

  // 大量のデータをセットし、全てのノードの再計算を行う。O(N)
  void Set(const vector<Element>& vs) {
    int index = 0;
    while (hasChild(index)) index = lchild(index);

    F0R(i, min<int>(vs.size(), this->size)) {
      es[index++] = vs[i];
    }

    recalc();
  }

  void Set(const Lazy& value, int left, int right, int segIndex = 0) {

    //cout << "Set " << "[" << left << ", " << right << ") si=" << segIndex << newl;

    if (left <= lefts[segIndex] && rights[segIndex] <= right) {
      add(segIndex, value);
      resolve(segIndex);
    }
    else {
      resolve(segIndex);

      auto l = lchild(segIndex), r = rchild(segIndex);
      if (left < mp[segIndex]) {
        Set(value, left, right, l);
      }
      else {
        resolve(l);
      }
      if (mp[segIndex] < right) {
        Set(value, left, right, r);
      }
      else {
        resolve(r);
      }

      es[segIndex] = mergeTT(es[l], es[r]);
    }
  }

  Element Get(int left, int right, int segIndex = 0) {

    if (right <= left) return Element();

    resolve(segIndex);
    if (left <= lefts[segIndex] && rights[segIndex] <= right) {
      return es[segIndex];
    }
    else {
      if (left < mp[segIndex]) {
        if (mp[segIndex] < right) {
          return mergeTT(Get(left, right, lchild(segIndex)), Get(left, right, rchild(segIndex)));
        }
        return Get(left, right, lchild(segIndex));
      }
      else if (mp[segIndex] < right) {
        return Get(left, right, rchild(segIndex));
      }
    }
  }

  void Print(ECallback c) {
    F0R(i, es.size()) {
      c(es[i], ls[i]);

      if (((i + 2) & (i + 1)) == 0) {
        cout << "." << newl;
      }
    }
  }

protected:

  void resolve(int segIndex) {
    if (!lazyFlag[segIndex]) return;

    mergeTE(es[segIndex], ls[segIndex], rights[segIndex] - lefts[segIndex]);

    if (hasChild(segIndex)) {
      auto l = lchild(segIndex), r = rchild(segIndex);
      add(l, ls[segIndex]);
      add(r, ls[segIndex]);
    }

    ls[segIndex] = Lazy();
    lazyFlag[segIndex] = false;
  }

  // 遅延データを追加
  void add(int segIndex, const Lazy& value) {

    if (lazyFlag[segIndex]) {
      mergeEE(ls[segIndex], value);
    }
    else {
      //cout << "set index" << segIndex << newl;
      ls[segIndex] = value;
      lazyFlag[segIndex] = true;
    }
  }

  // 指定したノードと全ての子を計算。一度に大量のデータの変更があったときのみ
  void recalc(int segIndex = 0) {
    if (hasChild(segIndex)) {
      recalc(lchild(segIndex));
      recalc(rchild(segIndex));
      es[segIndex] = mergeTT(es[lchild(segIndex)], es[rchild(segIndex)]);
    }
  }

  A mergeTT;
  B mergeTE;
  C mergeEE;

  // 要素ごとのデータ
  vector<Element> es;

  // 要素ごとの遅延データ
  vector<Lazy> ls;

  // 遅延データがあるか
  vector<bool> lazyFlag;

  // 区間 [l, r) とその中間
  vector<int> lefts, rights, mp;

  // 区間のサイズ = 子を持たないエレメント数
  int size;
};


// INSERT ABOVE HERE
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, Q;
  cin >> N >> Q;
  vector<vector<int>> G(N);
  F0R(i, N - 1) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vector<int> as(N);

  F0R(i, Q) {
    int p, x;
    cin >> p >> x;
    as[p - 1] += x;
  }

  vector<int> rs(N);

  auto dfs = [&](auto dfs, int v, int p, int val)->void {
    val += as[v];
    rs[v] = val;

    for (auto c : G[v]) {
      if (c == p) continue;
      dfs(dfs, c, v, val);
    }
  };
  dfs(dfs, 0, -1, 0);

  F0R(i, N) {
    cout << rs[i] << ' ';
  }
}
#endif
