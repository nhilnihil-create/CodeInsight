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

int main() {
  int n; cin >> n;
  string s; cin >> s;
  vector<int> sa(n);
  for (int i = 0; i < n; ++i) sa[i] = s[i] % 3;
  vector<int> cnt(3, 0);
  for (int i = 0; i < n; ++i) ++cnt[sa[i]];
  ll ans = 1;
  for (int i = 0; i < 3; ++i) ans *= (ll)cnt[i];

  for (int j = 0; j < n; ++j)
    for (int i = 0; i < j; ++i) {
      int k = (j - i) + j;
      if (k < n) {
        if (s[i] == s[j]) continue;
        if (s[i] == s[k]) continue;
        if (s[j] == s[k]) continue;

        --ans;
      }
    }
  cout << ans << endl;
}
