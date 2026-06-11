#include <bits/stdc++.h>

#define MAX_NUM (1000000000 + 7)

typedef uint64_t u64;
typedef int64_t i64;
typedef uint32_t u32;
typedef int32_t i32;

using namespace std;

template <typename T>
static inline void ArrayInput(vector<T>& A) {
  for (auto itr = A.begin(); itr < A.end(); ++itr) cin >> *itr;
}

template <typename T>
static inline void ArrayPut(const vector<T>& A) {
  for (auto itr = A.begin(); itr < A.end(); ++itr) cout << *itr << " ";
  cout << endl;
}

template <typename T>
static inline T ArraySum(vector<T>& A) {
  T res = 0;
  for (auto itr = A.begin(); itr < A.end(); ++itr) res += *itr;
  return res;
}

bool Sec_compare(pair<uint64_t, uint64_t> a, pair<uint64_t, uint64_t> b) {
  if (a.second != b.second) {
    return a.second < b.second;
  } else {
    return a.first < b.first;
  }
}

u64 dec_dig(u64 num) {
  u64 res = 0;
  while (num > 0) {
    num /= 10;
    ++res;
  }
  return res;
}

u64 gcd(u64 a, u64 b) {
  if (a < b) {
    a ^= b;
    b ^= a;
    a ^= b;
  }

  return b ? gcd(b, a % b) : a;
}

char Map[2000][2000];
u32 L[2000][2000], R[2000][2000], U[2000][2000], D[2000][2000];

int main() {
  cout << setprecision(18);
  u32 H, W;
  cin >> H >> W;
  for (u32 i = 0; i < H; ++i) {
    for (u32 j = 0; j < W; ++j) {
      cin >> Map[i][j];
    }
  }
  for (u32 i = 0; i < H; ++i) {
    for (u32 j = 0; j < W; ++j) {
      if (Map[i][j] == '#') {
        L[i][j] = 0;
        U[i][j] = 0;
      } else {
        L[i][j] = (j == 0) ? 1 : L[i][j - 1] + 1;
        U[i][j] = (i == 0) ? 1 : U[i - 1][j] + 1;
      }
      if (Map[i][W - (j + 1)] == '#')
        R[i][W - (j + 1)] = 0;
      else
        R[i][W - (j + 1)] = (j == 0) ? 1 : R[i][W - j] + 1;
      if (Map[H - (i + 1)][j] == '#')
        D[H - (i + 1)][j] = 0;
      else
        D[H - (i + 1)][j] = (i == 0) ? 1 : D[H - i][j] + 1;
    }
  }
  u32 res = 0;
  for (u32 i = 0; i < H; ++i) {
    for (u32 j = 0; j < W; ++j) {
      u32 tmp;
      if (Map[i][j] == '#') continue;
      tmp = L[i][j] + R[i][j] + U[i][j] + D[i][j] - 3;
      if (tmp > res) res = tmp;
    }
  }
  cout << res << endl;
  return 0;
}
