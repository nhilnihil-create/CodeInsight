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
  vector<vector<pair<int,int>>> G(N);
  F0R(i, N - 1) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].emplace_back(b, i);
    G[b].emplace_back(a, i);
  }

  i64 K = 1;
  vector<int> cs(N-1);
  auto dfs = [&](auto dfs, int v, int pc, int p = -1)->void {

    int cl = 1;
    for (auto e : G[v]) {
      if (e.first == p) continue;
      if (cl == pc) cl++;

      cs[e.second] = cl;
      chmax(K, cl);
      dfs(dfs, e.first, cl, v);

      cl++;
    }
  };
  dfs(dfs, 0, 0);

  cout << K << newl;
  F0R(i, cs.size()) {
    cout << cs[i] << newl;
  }
}
#endif
