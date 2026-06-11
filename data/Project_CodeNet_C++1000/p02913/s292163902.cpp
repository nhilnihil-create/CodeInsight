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


template<class T>
vector<int> ZAlgorithm(const T& src) {
  vector<int> A(src.size());
  A[0] = src.size();
  int i = 1, j = 0;
  while (i < src.size()) {
    while (i + j < src.size() && src[j] == src[i + j]) ++j;
    A[i] = j;
    if (j == 0) { ++i; continue; }
    int k = 1;
    while (i + k < src.size() && k + A[k] < j) A[i + k] = A[k], ++k;
    i += k; j -= k;
  }
  return move(A);
}

// INSERT ABOVE HERE
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N;
  string S;
  cin >> N >> S;

  int result = 0;
  while (S.size()) {
    auto zs = ZAlgorithm(S);
    F0R(i, zs.size()) {
      chmax(result, min(zs[i], i));
    }
    S.erase(S.begin());
  }
  cout << result;
}
#endif
