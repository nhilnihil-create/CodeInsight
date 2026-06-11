#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int X;
  cin >> X;
  ll ans = 0;
  ll time = X / 500;
  ans += time * 1000;
  X -= time * 500;
  time = X / 5;
  ans += time * 5;
  cout << ans << '\n';
  return 0;
}