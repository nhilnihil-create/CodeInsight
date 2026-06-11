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
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<int> ans(n + 1);
  int m = 0;
  for (int i = n; i >= 1; --i) {
    int cnt = 0;
    for (int j = 1; i * j <= n; ++j) {
      if (ans[i * j]) cnt++;
    }
    cnt %= 2;
    if (cnt != a[i]) {
      m++;
      ans[i]++;
    }
  }
  cout << m << endl;
  if (m) {
    for (int i = 1; i <= n; ++i) {
      if (ans[i]) cout << i << endl;
    }
  }
  return 0;
}