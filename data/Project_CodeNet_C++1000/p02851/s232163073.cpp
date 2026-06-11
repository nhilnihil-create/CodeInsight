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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<ll> sum(n + 1);
  for (int i = 0; i < n; ++i) {
    sum[i + 1] = sum[i] + a[i];
  }
  vector<ll> t(n + 1);
  for (int i = 0; i <= n; ++i) {
    t[i] = (sum[i] - i) % k;
  }
  ll ans = 0;
  map<ll, ll> mp;
  for (int i = 0; i <= n; ++i) {
    if (0 <= i - k) {
      mp[t[i - k]]--;
    }
    ans += mp[t[i]];
    mp[t[i]]++;
  }
  cout << ans << endl;
  return 0;
}