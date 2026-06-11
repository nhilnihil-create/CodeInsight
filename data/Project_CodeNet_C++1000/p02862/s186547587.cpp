#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
const int MAX = 2*1e6+1;
ll fact[MAX], inv[MAX], finv[MAX];
void COM() {
  fact[0] = fact[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;

  for (int i = 2; i < MAX; i++)
  {
    fact[i] = i * fact[i-1] % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
    finv[i] = inv[i] * finv[i-1] % MOD;
  }
}

ll combination(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fact[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}

int main() {
  int x, y;
  cin >> x >> y;
  int a = (2*y-x), b = (2*x-y);
  if (a < 0 || b < 0 || a%3 != 0 || b%3 != 0) {
    cout << 0 << endl;
    return 0;
  }
  
  COM();
  a /= 3;
  b /= 3;
  //cout << a << ' ' << b << endl;
  cout << combination(a+b,a) << endl;
  return 0;
}