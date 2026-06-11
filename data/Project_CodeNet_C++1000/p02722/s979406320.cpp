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

vector<ll> divisor(ll n) {
  vector<ll> res;
  for (ll i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      res.push_back(i);
      if (i != n / i) res.push_back(n / i);
    }
  }
  return res;
}

int count(ll n, vector<ll> vec) {
  int res = 0;
  for (int i = 0; i < vec.size(); ++i) {
    if (vec[i] == 1) continue;
    ll value = n, k = vec[i];
    while (k <= value) {
      if (value % k == 0) {
        value /= k;
      } else {
        value %= k;
      }
    }
    if (value == 1) res++;
  }
  return res;
}

int main() {
  ll n;
  cin >> n;
  vector<ll> d1 = divisor(n - 1);
  vector<ll> d2 = divisor(n);
  int ans = 0;
  ans += count(n, d1);
  ans += count(n, d2);
  cout << ans << endl;
  return 0;
}