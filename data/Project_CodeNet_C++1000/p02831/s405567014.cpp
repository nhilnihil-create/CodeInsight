#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

ll gcd(ll a, ll b) {
  while (b) {
    ll c = b;
    b = a % b;
    a = c;
  }
  return a;
}

ll lcm(ll a, ll b) {
  if (!a || !b) return 0;
  return a * b / gcd(a, b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll a, b;
  cin >> a >> b;
  cout << lcm(a, b);
  return 0;
}
