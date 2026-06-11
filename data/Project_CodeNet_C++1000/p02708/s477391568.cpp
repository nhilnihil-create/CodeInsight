#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
  ll N, K;
  cin >> N >> K;
  ll res = 0;
  for (ll k = K; k <= N + 1; k++) {
    ll first = k * (k - 1) / 2;
    ll last  = k * (2 * N - k + 1) / 2;
    res = (res + last - first + 1) % MOD;
  }
  cout << res << endl;
  return 0;	
}