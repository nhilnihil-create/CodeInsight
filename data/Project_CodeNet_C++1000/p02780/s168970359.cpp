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
  int n, k;
  cin >> n >> k;
  vector<int> f (n+1);
  for (int i = 0; i < n; i++) {
    cin >> f[i+1];
    f[i+1] += f[i];
  }

  int ans = 0;
  for (int i = k; i <= n; i++) {
    ans = max(ans, f[i] - f[i-k]);
  }

  cout << fixed << setprecision(9) << (double) (ans+k) / 2.0 << endl;
}

int main() {
  setIO();
  while (tt--) {
    solve();
  }
  return 0;
}