#include <bits/stdc++.h>

//#include <atcoder/all>

using namespace std;
// using namespace atcoder;
using ll = long long;

map<ll, int> prime_fact(ll n) {
  map<ll, int> m;
  for (ll p = 2; p * p <= n; p++) {
    if (n % p) continue;  // 素因数でない
    int num = 0;
    while (!(n % p)) {  // 素因数で何回割れるかを計算する
      num++;
      n /= p;
    }
    m[p] = num;
  }
  if (n > 1) {  // n自身が素因数
    m[n] = 1;
  }

  return m;
}

int main() {
  ll a, b;
  cin >> a >> b;

  // 素数の公約数を選べば、それが答え。
  ll g = gcd(a, b);

  // 最大公約数の素因数を数えれば良い
  auto p = prime_fact(g);
  cout << p.size() + 1 << endl;
}