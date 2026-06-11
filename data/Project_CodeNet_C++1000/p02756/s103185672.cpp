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

struct query {
    i32 t, f, c;
};


int main() {
  string s;
  i32 q;
  cin >> s >> q;

  vector<query> qs(q);

  bool rev = false;

  string left, right;

  rep(i, q) {
    i32 qi;
    cin >> qi;
    if (qi == 1) {
      rev = !rev;
    } else if (qi == 2) {
      i32 f;
      char c;
      cin >> f >> c;

      if ((f == 1 && !rev) || (f == 2 && rev)) {
        left += c;
      } else {
        right += c;
      }
    }
  }


  if (rev) {
    reverse(s.begin(), s.end());
    reverse(right.begin(), right.end());
    s = right + s + left;
  } else {
    reverse(left.begin(), left.end());
    s = left + s + right;
  }

  cout << s;

  return 0;
}
