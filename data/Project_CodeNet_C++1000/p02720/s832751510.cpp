#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int k;
  cin >> k;
  if (1 <= k && k <= 9) {
    cout << k;
    return 0;
  }
  queue<ll> que;
  rep(i, 9) { que.push(i + 1); }
  ll cnt = 9;
  while (1) {
    ll x = que.front();
    if (x % 10 != 0) {
      que.push(10 * x + (x % 10) - 1);
      cnt++;
      if (cnt == k) {
        break;
      }
    }
    que.push(10 * x + (x % 10));
    cnt++;
    if (cnt == k) {
      break;
    }
    if (x % 10 != 9) {
      que.push(10 * x + (x % 10) + 1);
      cnt++;
      if (cnt == k) {
        break;
      }
    }
    que.pop();
  }
  cout << que.back() << endl;
  return 0;
}