#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define DD long double

#define M 1000000007
#define INF 1e18

void setIO(string s = "") { 
  cin.sync_with_stdio(0); cin.tie(0);
  if (s.size()) s += ".in", freopen(s.c_str(), "r", stdin);
}

int tt = 1;
void solve() {
  int n, c = 0, sm;
  cin >> n;
  vector<int> f (n);
  for (auto& it : f) cin >> it;
  sm = f[0];
  for (int i = 0; i < n; i++) {
    if (f[i] <= sm) c++, sm = min(f[i], sm);
  }
  cout << c << endl;
}

int main() {
  setIO();
  while (tt--) {
    solve();
  }
  return 0;
}