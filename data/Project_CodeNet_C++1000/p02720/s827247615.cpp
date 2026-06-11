#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int k;
  cin >> k;

  queue<ll> q;
  for (ll i = 1; i <= 9; i++) q.push(i);

  ll x;
  rep(i, k) {
    x = q.front();
    q.pop();
    if (x % 10 != 0) q.push(10 * x + x % 10 - 1);
    q.push(10 * x + x % 10);
    if (x % 10 != 9) q.push(10 * x + x % 10 + 1);
  }

  cout << x << endl;
  return 0;
}
