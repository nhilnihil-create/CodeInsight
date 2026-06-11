#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
const int INF = 1000000009;
const ll LINF = 1e18;

int main() {
  int n;
  cin >> n;
  vector<int> np(n);
  for (int i = 0; i < n; ++i) np[i] = i + 1;
  vector<int> p(n), q(n);
  for (int i = 0; i < n; ++i) cin >> p[i];
  for (int i = 0; i < n; ++i) cin >> q[i];

  int cnt = 0;
  int cnt_p, cnt_q;
  do {
    ++cnt;
    // cout << cnt << " " << np[0] << " " << np[1] << " " << np[2] << endl;
    bool chk_p = true;
    for (int i = 0; i < n; ++i) {
      if (p[i] != np[i]) chk_p = false;
    }
    if (chk_p == true) cnt_p = cnt;

    bool chk_q = true;
    for (int i = 0; i < n; ++i) {
      if (q[i] != np[i]) chk_q = false;
    }
    if (chk_q == true) cnt_q = cnt;
  } while (next_permutation(np.begin(), np.end()));

  cout << abs(cnt_p - cnt_q) << endl;
}
