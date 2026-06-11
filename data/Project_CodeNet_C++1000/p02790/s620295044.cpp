#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  char a, b;
  cin >> a >> b;
  if (a > b) swap(a, b);
  string ans;
  int time = b - '0';
  rep(i, time) ans += a;
  cout << ans << '\n';
  return 0;
}