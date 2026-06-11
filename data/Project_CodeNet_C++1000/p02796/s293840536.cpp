#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  int n;
  cin >> n;
  vector<vector<ll>> t(n, vector<ll>(2, 0));
  for(int i = 0; i < n; i++) {
    ll x, l;
    cin >> x >> l;
    t[i][0] = x + l;
    t[i][1] = x - l;
  }
  sort(t.begin(), t.end());
  ll r = -1001001001;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    if(r > t[i][1]) {
      continue;
    }
    ans++;
    r = max(r, t[i][0]);
  }
  cout << ans << endl;
  return 0;
}