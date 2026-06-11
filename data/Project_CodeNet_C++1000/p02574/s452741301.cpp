#include <bits/stdc++.h>

typedef uint64_t u64;
typedef int64_t i64;
typedef uint32_t u32;
typedef int32_t i32;
typedef uint16_t u16;
typedef int16_t i16;
typedef uint8_t u8;
typedef int8_t i8;

using namespace std;

#define rep(idx, N) for (u64 idx = 0; idx < N; idx++)

vector<u32> min_p(1000006);

int main() {
  u32 n;
  cin >> n;

  vector<u32> a(n);
  rep(i, n) cin >> a[i];

  min_p[0] = 1;
  for (u32 i = 1; i < min_p.size(); i++) {
    min_p[i] = i;
    for (u32 j = 2; j * j < i; j++) {
      if (i % j == 0) {
        min_p[i] = j;
        break;
      }
    }
  }

  bool sc = true;
  u32 g = gcd(a[0], a[1]);
  for (u32 i = 2; i < n; i++) {
    g = gcd(g, a[i]);
  }
  if (g != 1)
    sc = false;

  unordered_map<u32, u64> m;
  unordered_set<u32> plist;

  rep(i, n) {
    plist.clear();
    while (1) {
      plist.insert(min_p[a[i]]);
      a[i] /= min_p[a[i]];
      if (min_p[a[i]] == a[i]) {
        plist.insert(a[i]);
        break;
      }
    };

    for (auto d : plist) {
      m[d]++;
    }
  }

  bool pc = true;

  for (auto p : m) {
    if (p.first != 1 && p.second > 1)
      pc = false;
  }

  if (pc)
    cout << "pairwise coprime";
  else if (sc)
    cout << "setwise coprime";
  else
    cout << "not coprime";

  return 0;
}
