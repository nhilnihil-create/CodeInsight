#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cmath>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  priority_queue<pair<int, int>> que;
  rep(i, n) cin >> a[i];
  rep(i, n) {
    cin >> b[i];
    if (b[i] != a[i])
      que.push({b[i], i});
  }
  ll ans = 0;
  while (!que.empty()) {
    int tmp, idx;
    tie(tmp, idx) = que.top();
    que.pop();
    int l = (idx+n-1)%n, r = (idx+n+1)%n;
    if (b[l] == a[l] && b[r] == a[r]) {
      if ((b[idx]-a[idx])%(b[l]+b[r])) {
        cout << -1 << endl;
        return 0;
      }
      ans += (b[idx]-a[idx])/(b[l]+b[r]);
      b[idx] = a[idx];
    } else {
      int sub = b[idx]-max(b[l], b[r]);
      int num = (sub+b[l]+b[r]-1)/(b[l]+b[r]);
      b[idx] -= (b[l]+b[r])*num;
      ans += num;
      if (sub <= 0 || b[idx] < a[idx]) {
        cout << -1 << endl;
        return 0;
      }
      if (b[idx] > a[idx])
        que.push({b[idx], idx});
    }
  }
  cout << ans << endl;
  return 0;
}