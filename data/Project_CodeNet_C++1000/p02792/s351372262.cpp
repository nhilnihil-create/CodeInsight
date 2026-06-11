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
LL f[10][10];
int tt = 1;
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string s = to_string(i);
    int size = s.size();
    int t = s[0] - '0';
    int b = s[s.size() - 1] - '0';
    f[t][b]++;
  }
  LL c = 0;
  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) c += f[i][j] * f[j][i];
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