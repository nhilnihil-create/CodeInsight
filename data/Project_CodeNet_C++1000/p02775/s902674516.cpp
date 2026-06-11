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

  string S;
  cin >> S;

  i64 result = 0;
  int k = 0;  // 繰り上がり

  RF0(i, S.size()) {
    int n = S[i] - '0' + k;
    k = 0;

    bool pay = n <= 5;

    // 今回5でも次が5以上なら、繰り上げた方が少なく済む
    // 55に対し、100払ったほうが105払うより良いということ
    if (n == 5 && i > 0 && S[i - 1] - '0' >= 5) pay = false;

    if (pay) {
      // n 払う
      result += n;
    }
    else {
      // 10 - n 釣りをもらって、次の桁+1
      result += 10 - n;
      k++;
    }
  }
  result += k;

  cout << result;
}
#endif
