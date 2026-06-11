#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
  int k;
  cin >> k;

  ll sum = 0;

  rep(a, k) {
    rep(b, k) {
      rep(c, k) { sum += gcd(gcd(a + 1, b + 1), c + 1); }
    }
  }

  cout << sum << endl;

  return 0;
}
