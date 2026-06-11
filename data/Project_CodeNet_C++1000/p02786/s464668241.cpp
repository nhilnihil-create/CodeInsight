#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll attack(ll n) {
  if (n == 1) return 1;
  return 1 + 2 * attack(n/2);
}

int main() {
  ll N;
  cin >> N;
  ll ans = attack(N);
  cout << ans << '\n';
  return 0;
}