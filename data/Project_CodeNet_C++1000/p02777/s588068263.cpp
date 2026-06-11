
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
  string a, b;
  cin >> a >> b;
  int aa, bb;
  cin >> aa >> bb;
  string u;
  cin >> u;
  if (u == a) {
    cout << aa-1 << " " << bb << endl;
  }else {
    cout << aa << " " << bb-1 << endl; 
  }
}

int main() {
  setIO();
  while (tt--) {
    solve();
  }
  return 0;
}