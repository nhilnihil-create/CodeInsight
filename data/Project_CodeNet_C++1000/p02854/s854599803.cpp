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
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<ll> l(n + 2), r(n + 2);
  for (int i = 0; i < n; ++i) {
    l[i + 1] = l[i] + a[i];
  }
  for (int i = n; i >= 1; --i) {
    r[i] = r[i + 1] + a[i - 1];
  }
  ll ans = 1e18;
  for (int i = 1; i < n; ++i) {
    ans = min(ans, abs(l[i] - r[i + 1]));
  }
  cout << ans << endl;
  return 0;
}