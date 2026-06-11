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

int n;
ll k;
vector<int> a, f;

bool check(ll x) {
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    res += max(0ll, 1ll * (a[i] - (x / f[i])));
  }
  return res <= k;
}

int main() {
  cin >> n >> k;
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  f.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> f[i];
  }
  sort(a.begin(), a.end());
  sort(f.rbegin(), f.rend());
  ll mx_a = *max_element(a.begin(), a.end());
  ll mx_f = *max_element(f.begin(), f.end());
  ll ok = 1ll * mx_a * mx_f, ng = -1;
  while (1 < abs(ok - ng)) {
    ll mid = (ok + ng) / 2;
    if (check(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  cout << ok << endl;
  return 0;
}