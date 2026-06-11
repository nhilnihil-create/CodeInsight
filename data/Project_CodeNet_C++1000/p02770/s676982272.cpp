#pragma GCC optimize("Ofast")
#define _USE_MATH_DEFINES
#include "bits/stdc++.h"

using namespace std;

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using i8 = int8_t;
using i32 = int32_t;
using i64 = int64_t;

constexpr char newl = '\n';
constexpr double eps = 1e-10;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,b) FOR(i,0,b)
#define RFO(i,a,b) for (int i = ((b)-1); i >=(a); i--)
#define RF0(i,b) RFO(i,0,b)
//#define fi first
//#define se second
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

  int k, q;
  cin >> k >> q;

  vector<int> ds(k);
  F0R(i, k) {
    cin >> ds[i];
  }

  vector<tuple<int,int,int>> qs;
  qs.reserve(q);
  F0R(i, q) {
    int n, x, m;
    cin >> n >> x >> m;
    qs.emplace_back(n, x, m);
  }

  // d を全てmod m にする。その後 0 を m にする。この数列をAとする
  // x を mod m してから、A を順に n-1 個足して、何回 m 以上になるか、をBとする
  // n - B が答え

  for (auto query : qs) {
    int n, x, m;
    tie(n, x, m) = query;

    vector<int> as;
    i64 sum = 0;
    as.reserve(k);
    F0R(i, k) {
      as.push_back(ds[i] % m);
      if (!as[i]) as[i] = m;
      sum += as[i];
    }

    x %= m;

    // x に 数列から n-1 個足す
    n--;
    i64 r = x + (n / k) * sum;
    F0R(i, n% k) {
      r += as[i];
    }

    cout << (n - r / m) << newl;
  }
}
#endif
