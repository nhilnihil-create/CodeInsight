#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll g1(ll n, ll p) {
  if (n == 0) return  0;
  return n/p + g1(n/p, p);
}

ll g2(ll n, ll p) {
  // 二重階乗
  if (n&1) return g1(n, p) - g2(n-1, p);
  ll res = g1(n/2, p);
  if (p == 2) res += n/2;
  return res;
}

int main() {
  // 二重階乗（Double Factorial）、二重階乗が2と5で何回割れるか
  ll N;
  cin >> N;
  ll ans = min(g2(N, 2), g2(N, 5));
  cout << ans << '\n';
  return 0;
}