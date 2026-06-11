#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int k;
  cin >> k;
  if (k <= 9) {
    cout << k << endl;
    return 0;
  }

  queue<ll> q;
  for (int i = 1; i <= 9; i++) q.push(i);
  ll x;
  while (k != 0) {
    x = q.front();
    q.pop();
    k--;

    int a = x % 10;
    if (a == 0) {
      q.push(x * 10);
      q.push(x * 10 + 1);
    } else if (a == 9) {
      q.push(x * 10 + 8);
      q.push(x * 10 + 9);
    } else {
      q.push(x * 10 + a - 1);
      q.push(x * 10 + a);
      q.push(x * 10 + a + 1);
    }
  }

  cout << x << endl;
  return 0;
}