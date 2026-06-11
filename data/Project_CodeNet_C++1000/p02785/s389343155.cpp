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
  LL n, k, sum = 0;
  cin >> n >> k;
  vector<LL> f (n);
  for (auto &it : f) cin >> it;
  sort(f.begin(), f.end());
  for (int i = 0; i < n-k; i++) {
    sum += f[i];
  }
  cout << sum << endl;
}

int main() {
  setIO();
  while (tt--) {
    solve();
  }
  return 0;
}