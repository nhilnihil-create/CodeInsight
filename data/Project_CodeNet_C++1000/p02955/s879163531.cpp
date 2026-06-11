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

template <typename U>
map<U, int> doPrimeFactorization(U n) {

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

template<typename T>
vector<T> getCompositeNums(map<T, int> primeNums) {

  vector<T> results;

  if (primeNums.empty()) {
    return results;
  }

  // どの素数を何個ずつ掛け合わせるか
  auto cur(primeNums);
  for (auto& c : cur) {
    c.second = 0;
  }

  auto it = cur.begin();
  while (true) {
    if (++it == cur.end()) {
      u64 com = 1;
      for (auto& c : cur) {
        com *= pow<u64>(c.first, c.second);
#if 0
        cout << c.first << "," << c.second << '\n';
#endif
      }
      if (com > 1) {
        results.push_back(com);
#if 0
        cout << com << '\n';
#endif
      }

      bool end = false;
      while (true) {
        if (it == cur.begin()) {
          end = true;
          break;
        }
        it--;
        if (++(it->second) > primeNums[it->first]) {
          it->second = 0;
          continue;
        }
        break;
      }
      if (end) {
        break;
      }
    }
  }

  sort(results.begin(), results.end());
  return results;
}

// INSERT ABOVE HERE
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  // A1,A2,...,ANの合計をsumとする
  // Kが十分に大きいとき、解はsumとなる
  // そうでないときはsumの約数

  int N, K;
  cin >> N >> K;
  vector<int> as(N);
  int sum = 0;
  F0R(i, N) {
    cin >> as[i];
    sum += as[i];
  }

  auto cs = getCompositeNums(doPrimeFactorization(sum));

  // K回以内の操作で指定したGCDを達成できるか？
  auto check = [&](int v)->bool {
    vector<int> bs(N);
    F0R(i, N) {
      bs[i] = as[i] % v;
    }
    sort(rng(bs));
    int l = 0, r = N - 1, k = 0;  // 操作数
    int n = 0;  // LをマイナスしてRをプラスする、その数
    while (bs[r] && k <= K) {
      if (n >= 0) {
        // L をマイナス
        while (!bs[l]) l++;
        k += bs[l];
        n -= bs[l];
        bs[l] = 0;
        l++;
      }
      else {
        // R をプラス
        //k += v - bs[r];
        n += v - bs[r];
        bs[r] = 0;
        r--;
      }
    }

    return k <= K;
  };

  RF0(i, cs.size()) {
    //debug(cs[i]);
    if (check(cs[i])) {
      cout << cs[i];
      return 0;
    }
  }
  cout << 1;
}
#endif
