#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<ll> cnt(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i]--;
    cnt[a[i]]++;
  }
  ll total = 0;
  for (int i = 0; i < n; ++i) {
    total += cnt[i] * (cnt[i] - 1) / 2;
  }
  for (int i = 0; i < n; ++i) {
    ll ans = total;
    ans -= cnt[a[i]] * (cnt[a[i]] - 1) / 2;
    ans += max(0ll, (cnt[a[i]] - 1) * (cnt[a[i]] - 2) / 2);
    cout << ans << endl;
  }
  return 0;
}