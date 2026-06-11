#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

const ll mod = pow(10, 9) + 7;

int main()
{
  ll n, k;
  cin >> n >> k;
  ll res = 0;
  vector<ll> sum(n + 2 - k);
  for (ll i = k; i <= n + 1; i++) {
    res += (i * (n - i + 1) + 1) % mod;
  }
  cout << res % mod << endl;

  return 0;
}
