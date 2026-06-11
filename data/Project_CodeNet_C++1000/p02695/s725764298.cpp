
#include <bits/stdc++.h>
#include <iostream>
#include <string>

typedef uint64_t u64;
typedef int64_t i64;
typedef uint32_t u32;
typedef int32_t i32;
typedef uint16_t u16;
typedef int16_t i16;
typedef uint8_t u8;
typedef int8_t i8;

using namespace std;

#define REP(idx, N) for (u64 idx = 0; idx < N; idx++)

u32 rec(vector<u32> &vec, u32 &ans, u32 n, function<u32(vector<u32> &)> eval) {
  u32 v = ans;
  if (n == 0) {
    v = eval(vec);
    ans = max(ans, v);
    return ans;
  }
  REP(i, vec[n]) {
    vec[n - 1] = i + 1;
    v = max(v, rec(vec, ans, n - 1, eval));
  }
  return v;
}

int main() {
  u32 N = 0, M, Q;

  cin >> N >> M >> Q;

  vector<u32> a(Q), b(Q), c(Q), d(Q);
  u32 ain, bin, _cin, din;

  REP(q, Q) {
    cin >> ain >> bin >> _cin >> din;
    a[q] = ain;
    b[q] = bin;
    c[q] = _cin;
    d[q] = din;
  }

  vector<u32> A(N + 1, M);
  u32 ans = 0;
  rec(A, ans, N, [&](vector<u32> &vec) {
    u32 sum = 0;
    REP(q, Q) {
      if (vec[b[q]] - vec[a[q]] == c[q]) {
        sum += d[q];
      }
    }
    return sum;
  });

  cout << ans;

  return 0;
}
