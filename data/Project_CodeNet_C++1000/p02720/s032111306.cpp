#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a; i < (int)(b); i++)
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP1(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
using ll = long long;
int pow(int a, int b, int mod) {
  if (b == 0) {
    return 1;
  } else if (b % 2 == 1) {
    return pow(a, b - 1, mod) * a % mod;
  }
  int c = pow(a, b / 2, mod);
  return c * c % mod;
}
int main() {
  int k;
  cin >> k;
  queue<ll> que;
  REP1(i, 9) { que.push(i); }
  REP(i, k - 1) {
    ll x = que.front();
    que.pop();
    if (x % 10 > 0) {
      que.push(10 * x + x % 10 - 1);
    }
    que.push(10 * x + x % 10);
    if (x % 10 < 9) {
      que.push(10 * x + x % 10 + 1);
    }
  }
  cout << que.front() << endl;
  return 0;
}
