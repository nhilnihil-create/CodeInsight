#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

void Main();

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(10);
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Main();
#ifdef LOCAL
  cout << "\nTime: " << (int)ceil((double)1000 * clock() / CLOCKS_PER_SEC) << " ms";
#endif
}

const int MOD = (int)1e9 + 7;
int n;
vector<int> p2(60), cnt_one(60, 0), cnt_zero(60, 0);
int ans = 0;

inline int mult(int a, int b) {
  return 1ll * a * b % MOD;
}

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
  return a;
}

void Main() {
  p2[0] = 1;
  for (int i = 1; i < 60; i++) {
    p2[i] = mult(p2[i - 1], 2);
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    for (ll bit = 0; bit < 60; bit++) {
      if (a & (1ll << bit)) {
        ans = add(ans, mult(cnt_zero[bit], p2[bit]));
        cnt_one[bit]++;
      } else {
        ans = add(ans, mult(cnt_one[bit], p2[bit]));
        cnt_zero[bit]++;
      }
    }
  }
  cout << ans << '\n';
}