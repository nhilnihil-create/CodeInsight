#include <iostream>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll pow(ll x, ll n) {
  ll res = 1;

  while (n > 0) {
    if (n % 2 == 1) res = res * x % MOD;
    x = x * x % MOD;
    n >>= 1;
  }

  return res;
}

int main() {
  ll n;
  cin >> n;

  cout << ((pow(10, n) - pow(9, n) * 2 + pow(8, n)) % MOD + MOD) % MOD << endl;
}
