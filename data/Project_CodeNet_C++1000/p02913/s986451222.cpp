#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <bitset>

using namespace std;

using ll = long long;
#define REP(i, n) for(int (i) = 0;(i) < (n);(i)++)

int n;
string s;

using i64 = int64_t;
const i64 B = 100000007;
const i64 MOD[3] = {998244353, 1000000007, 1000000009};
i64 t[3] = {1, 1, 1};
i64 sz;
vector<vector<i64>> Table;

bool func(int x) {

  map<i64, int> M[3];
  bool res = true;
  bitset<5000 + 10> bs[3];

  for (int i = 0; i < 3; i++) {

    int flag = 0;

    i64 mod = MOD[i];
    i64 t = 1;
    for (int j = 0; j < x; j++) {
      t = (t * B) % mod;
    }

    i64 h = 0;
    for (int j = 0; j < x; j++) {
      h = ((h * B) % mod + s[j]) % mod;
    }

    M[i][h] = x;

    for (int j = x; j < n; j++) {
      h = ((h * B) % mod + s[j]) % mod;
      h = (h + mod - ((s[j - x] * t) % mod)) % mod;
      if (M[i].count(h) && (j + 1 - M[i][h]) >= x) {
        bs[i][j] = 1;
      }
      if (!M[i][h]) M[i][h] = (j + 1);
    }

    bs[0] &= bs[i];
  }
  return bs[0].count() >= 1;
}

int main(void) {
  cin >> n >> s;
  int l = 0, r = n + 1;
  while (l + 1 != r) {
    int mid = (l + r) / 2;
    if (func(mid)) l = mid;
    else r = mid;
  }
  cout << l << '\n';
}

