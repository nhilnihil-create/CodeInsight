#include <cmath>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;

int n;
int k;

vi cnt(1e4);

void input() {
  cnt = vi(cnt.size());

  cin >> n >> k;
}

void solve() {
  for (int i = 0; i < k; ++i) {
    int d;
    cin >> d;

    for (int j = 0; j < d; ++j) {
      int t;
      cin >> t;

      cnt[t]++;
    }
  }

  int ans = 0;

  for (int i = 1; i <= n; ++i)
    ans += cnt[i] == 0;

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cout.precision(16);
  cout << fixed;

  int _times = 1;

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);

  _times = 2;
#endif

  // cin >> _times;

  while (_times--) {
    input();
    solve();
  }
}