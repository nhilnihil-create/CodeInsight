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

  int K;
  cin >> K;

  array<int, 32> arr{ 1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51 };

  cout << arr[K - 1];
}
