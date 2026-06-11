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
  vector<ll> a(n);
  int zero = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    zero += (a[i] == 0);
  }
  if (zero) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = 1;
  for (int i = 0; i < n; ++i) {
    ll tmp = 1e18;
    if (tmp / ans < a[i]) {
      cout << -1 << endl;
      return 0;
    }
    ans = ans * a[i];
  }
  cout << ans << endl;
  return 0;
}