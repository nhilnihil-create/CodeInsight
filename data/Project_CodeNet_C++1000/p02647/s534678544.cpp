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
  k = min(k, 60);
  vector<int> ans(n);
  for (int t = 0; t < k; ++t) {
    vector<int> tmp(n);
    for (int i = 0; i < n; ++i) {
      tmp[max(0, i - a[i])]++;
      if (i + a[i] + 1 < n) {
        tmp[i + a[i] + 1]--;
      }
    }
    for (int i = 1; i < n; ++i) {
      tmp[i] += tmp[i - 1];
    }
    a = tmp;
    ans = tmp;
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << (i == n - 1 ? '\n' : ' ');
  }
  return 0;
}