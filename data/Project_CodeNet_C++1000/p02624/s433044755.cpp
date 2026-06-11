#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#define ll long long
using namespace std;
const int MOD = 1000000007;
const ll INF = 1LL << 60;

vector<pair<ll, ll> > prime_factorize(ll N) {
  vector<pair<ll, ll> > res;
  for (ll a = 2; a * a <= N; ++a) {
    if (N % a != 0) continue;
    ll ex = 0;
    while (N % a == 0) {
      ++ex;
      N /= a;
    }
    res.push_back(pair<ll, ll>(a, ex));
  }
  if (N != 1) res.push_back(pair<ll, ll>(N, 1));
  return res;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;
  ll max = 10000000;
  vector<ll> a(max);
  for (ll i = 0; i < max; i++) {
    a[i] = 0;
  }
  for (ll i = 1; i <= max; i++) {
    ll point = i;
    for (ll j = 1; j * point <= max; j++) {
      a[j * point]++;
    }
  }

  ll ans = 0;

  for (ll i = 1; i <= n; i++) {
    ans += i * a[i];
  }
  cout << ans << endl;
}