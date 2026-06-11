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
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  priority_queue<int, vector<int> > que;
  for (int i = 0; i < n; ++i) {
    que.push(a[i]);
  }
  for (int i = 0; i < m; ++i) {
    int p = que.top();
    que.pop();
    p /= 2;
    que.push(p);
  }
  ll ans = 0;
  while (!que.empty()) {
    int p = que.top();
    que.pop();
    ans += p;
  }
  cout << ans << endl;
  return 0;
}