#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  cin >> N;
  ll ans = 0;
  for (int i = 1; i <= N; i++) {
    if (i%3 == 0 || i%5 == 0) continue;
    ans += i;
  }
  cout << ans << '\n';
  return 0;
}