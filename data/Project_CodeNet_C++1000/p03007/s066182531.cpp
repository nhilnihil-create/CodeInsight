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
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  queue<pair<int, int>> que;
  for (int i=1; i<n-1; i++) {
    if (a[i] >= 0) {
      que.push({a[0], a[i]});
      a[0] -= a[i];
    } else {
      que.push({a.back(), a[i]});
      a.back() -= a[i];
    }
  }
  que.push({a.back(), a[0]});
  a.back() -= a[0];
  cout << a.back() << endl;
  while (!que.empty()) {
    int x, y;
    tie(x, y) = que.front();
    que.pop();
    cout << x << ' ' << y << endl;
  }
  return 0;
}