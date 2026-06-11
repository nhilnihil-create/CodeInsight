#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  // 0からNまでに5の約数がどれくらい入っているか、Nが奇数の時は０
  ll N;
  cin >> N;
  if (N&1) {
    cout << 0 << '\n';
    return 0;
  }
  ll ans = 0;
  ll cur = 10;
  while (N/cur) {
    ans += N/cur;
    cur *= 5;
  }
  cout << ans << '\n';
  return 0;
}