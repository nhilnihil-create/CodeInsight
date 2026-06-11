#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main() {
  string L;
  cin >> L;

  ll n = L.size();

  vector<ll> dp1(n + 1); // A + B is less than L
  vector<ll> dp2(n + 1); // A + B can be L
  dp2[0] = 1;

  for (ll i = 0; i < n; i++) {
    if (L[i] == '0') {
      dp1[i + 1] = dp1[i] * 3 % mod;  // 00, 01, 10
      dp2[i + 1] = dp2[i] * 1 % mod;  // 00
    } else {
      dp1[i + 1] = dp1[i] * 3 % mod + // 00, 01, 10
                   dp2[i] * 1 % mod;  // 00
      dp2[i + 1] = dp2[i] * 2 % mod;  // 01, 10
    }
    dp1[i + 1] %= mod;
    dp2[i + 1] %= mod;
  }

  cout << (dp1[n] + dp2[n]) % mod << endl;
}
