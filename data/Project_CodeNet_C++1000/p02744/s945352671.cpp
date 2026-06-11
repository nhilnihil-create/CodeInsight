#include "bits/stdc++.h"

using namespace std;

using u32 = uint32_t;
using u64 = uint64_t;
using i64 = int64_t;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,b) FOR(i,0,b)
#define RFO(i,a,b) for (int i = (b-1); i >= a; i--)
#define RF0(i,b) RFO(i,0,b)
#define F first
#define S second
#define ADD(a,b) (((u64)a + b)%MOD)
#define MUL(a,b) (((u64)a * b)%MOD)

constexpr int MOD = 998244353;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  string s(N, 'a');

  while(true) {
    cout << s << '\n';
    
    auto it = s.end() - 1;

    if (it == s.begin()) {
      break;
    }

    auto cmax = [](const string& s, string::iterator it) {
      char c = 0;
      while (--it > s.begin()) {
        c = max(c, *it);
      }
      c = max(c, *it);
      return c;
    };

    bool end = false;
    while (++ * it - cmax(s, it) > 1) {
      it--;
      if (it == s.begin()) {
        end = true;
        break;
      }
    }
    if (end) {
      break;
    }
    while (++it < s.end()) {
      *it = 'a';
    }
  }
}
