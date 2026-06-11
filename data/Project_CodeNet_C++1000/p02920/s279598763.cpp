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

  // 2^18 = 262,144
  int N;
  cin >> N;
  map<int, int, greater<int>> ss;
  F0R(i, 1 << N) {
    int s;
    cin >> s;
    ss[s]++;
  }

  /*
  for (auto e : ss) {
    cout << e.first << ':' << e.second << newl;
  }
  return 0;
  //*/

  priority_queue<int> qu;
  qu.push(ss.begin()->first);
  
  if (!--ss.begin()->second) {
    ss.erase(ss.begin());
  }
  F0R(i, N) {
    priority_queue<int> qu2;
    while (qu.size()) {
      int q = qu.top();
      qu.pop();
      //debug(q);
      //debug(ss[si]);

      auto c = ss.begin();
      while (c->first >= q) {
        if (++c == ss.end()) {
          cout << "No";
          return 0;
        }
      }
      qu2.push(q);
      qu2.push(c->first);
      if (!--c->second) {
        ss.erase(c);
      }
    }
    qu = move(qu2);
  }
  cout << "Yes";
}
#endif
