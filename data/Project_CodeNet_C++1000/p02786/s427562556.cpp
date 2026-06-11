#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

ll counting(ll n) {
  if (n == 1)
    return 1;
  return counting(n / 2) * 2 + 1;
}

int main(void) {
  ll h;
  cin >> h;
  cout << counting(h) << '\n';
  return 0;
}