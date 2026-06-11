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


// INSERT ABOVE HERE
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  int vc = N * (N - 1) / 2;

  auto vn = [&](int i, int j) {
    if (i > j) swap(i, j);
    return((N - 1) + (N - i)) * i / 2 + j - i - 1;
  };

  vector<vector<int>> os(vc);
  vector<int> is(vc, 0);

  F0R(i, N) {
    int p, a;
    F0R(j, N - 1) {
      cin >> a;
      a--;
      if (j) {
        os[vn(i, p)].push_back(vn(i, a));
        is[vn(i, a)]++;
      }
      p = a;
    }
  }

  vector<int> vs;
  F0R(i, vc) {
    if (is[i] == 0) {
      vs.push_back(i);
    }
  }
  int rest = vc, result = 0;
  while (vs.size()) {

    vector<int> vs2;
    F0R(i, vs.size()) {
      for (auto c : os[vs[i]]) {
        if (!--is[c]) {
          vs2.push_back(c);
        }
      }
    }
    rest -= vs.size();
    if (rest < 0) break;
    result++;
    vs = move(vs2);
  }
  cout << (rest != 0 ? -1 : result);
}
#endif
