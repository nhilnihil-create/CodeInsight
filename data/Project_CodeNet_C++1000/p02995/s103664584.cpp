#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll C, D;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b;}

ll F(ll x) {
  ll res = x;
  res -= (x / C + x / D - x / lcm(C, D));
  return res;
}

int main() {
  ll A, B;
  cin >> A >> B >> C >> D;
  ll ans = F(B) - F(A-1);
  cout << ans << '\n';
  return 0;
}