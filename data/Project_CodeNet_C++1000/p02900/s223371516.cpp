#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
  ll a, b;
  cin >> a >> b;
  ll g = gcd(a, b);
  map<ll, ll> mp;
  for (ll i = 2; i * i <= g; ++i) {
    while (g % i == 0) {
      mp[i]++;
      g /= i;
    }
  }
  if (g != 1) mp[g]++;
  ll ans = 1;
  for (auto a : mp) ans++;
  cout << ans << endl;
  return 0;
}