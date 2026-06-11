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
  int n, a, c = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    if (i % 2 != 0 && a % 2 != 0) c++;
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