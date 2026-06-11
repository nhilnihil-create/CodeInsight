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


template <typename U>
map<U, int> doPrimeFactorization(U n) {
#define PrimeFactorization_DebugPrint false

  map<U, int> rs;
  U a = 1;

  while (!(n & 1)) {
    n >>= 1;
    rs[2]++;
  }

  for (U i = 3; i * i <= n; /*NOP*/) {
    auto q = n / i;
    auto r = n - i * q;
    if (r == 0) {
      rs[i]++;
      n = q;
    }
    else {
      i += 2;
    }
  }

  if (n > 1) {
    rs[n]++;
  }

  return move(rs);
}

// コレクションの重複要素を数え、<要素, 個数> のコレクションを返す
template<typename T>
map<T, int> countAllElements(const vector<T>& src) {
  map<T, int> results;

  for (auto& e : src) {
    auto it = results.find(e);
    if (it != results.end()) {
      it->second++;
    }
    else {
      results[e] = 1;
    }
  }

  return results;
}

// INSERT ABOVE HERE
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  // 整数列 A を全て 2 で割った整数列 B = b1, b2,...,bN
  // bk * (2p + 1) = X
  // つまりどの数にも奇数をかけて得られる最小公倍数がX
  // B に偶数が含まれていた場合、いずれのbkに対しても2がかけられている個数が同じでないといけない
  // そうでない場合は、個数は 0 になる
  // 最小公倍数を m とすると、m, 3m, 5m, 7m... が答えになるのでそれを数える
  
  int N, M;
  cin >> N >> M;

  map<int, int> mlcm;
  i64 lcm = 1;

  vector<int> as(N);
  bool fail = false;

  cin >> as[0];
  as[0] >>= 1;
  int ns = 0;
  while (!(as[0] & 1)) {
    as[0] >>= 1;
    ns++;
  }

  FOR(i, 1, N) {
    //int a;
    //cin >> a;
    cin >> as[i];
    as[i] >>= 1;

    int n = 0;
    while (!(as[i] & 1)) {
      as[i] >>= 1;
      n++;
    }
    if (n != ns) fail = true;
  }

  i64 result;
  if (fail) {
    //if (mlcm[2] > 0) {

    result = 0;
  }
  else {
    M >>= ns;

    F0R(i, N) {
      auto pf = doPrimeFactorization(as[i]);
      for (auto p : pf) {
        if (mlcm[p.first] < p.second) {

          //lcm *= pow<i64>(p.first, p.second - mlcm[p.first]);
          mlcm[p.first] = p.second;
        }
      }
    }
    for (auto p : mlcm) {
      lcm *= pow<i64>(p.first, p.second);
    }
    result = (M / lcm + 1) / 2;
  }

  cout << result;
}
#endif
