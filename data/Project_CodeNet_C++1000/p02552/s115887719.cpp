#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long

ll bow(ll x, ll y) {
  ll res = 1;
  for (ll i = 1; i <= y; ++i) {
    res = res * x % mod;
  }
  return res;
}

void solve() {
  ll x;
  cin >> x;
  cout << 1 - x << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}