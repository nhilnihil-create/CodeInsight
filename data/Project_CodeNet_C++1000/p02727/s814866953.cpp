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
  int x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  vector<int> p(a), q(b), r(c);
  for (int i = 0; i < a; ++i) {
    cin >> p[i];
  }
  for (int i = 0; i < b; ++i) {
    cin >> q[i];
  }
  for (int i = 0; i < c; ++i) {
    cin >> r[i];
  }
  sort(p.rbegin(), p.rend());
  sort(q.rbegin(), q.rend());
  vector<int> all;
  for (int i = 0; i < x; ++i) {
    all.push_back(p[i]);
  }
  for (int i = 0; i < y; ++i) {
    all.push_back(q[i]);
  }
  for (int i = 0; i < c; ++i) {
    all.push_back(r[i]);
  }
  sort(all.rbegin(), all.rend());
  ll ans = 0;
  for (int i = 0; i < x + y; ++i) {
    ans += all[i];
  }
  cout << ans << endl;
  return 0;
}