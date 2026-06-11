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
    a[i]--;
  }
  vector<ll> cnt(n);
  for (int i = 0; i < n; ++i) {
    cnt[a[i]]++;
  }
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += max(0ll, cnt[i] * (cnt[i] - 1) / 2);
  }
  for (int k = 0; k < n; ++k) {
    ll num = a[k];
    ll res = sum;
    res -= max(0ll, cnt[num] * (cnt[num] - 1) / 2);
    res += max(0ll, (cnt[num] - 1) * (cnt[num] - 2) / 2);
    cout << res << endl;
  }
  return 0;
}