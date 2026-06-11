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
const long long INF = 1LL << 60;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n, x, y;
  cin >> n >> x >> y;
  map<ll, ll> m;
  for (ll i = 1; i < n; i++) {
    for (ll j = i + 1; j < n + 1; j++) {
      ll stock = min(abs(x - i) + 1 + abs(j - y), abs(y - i) + 1 + abs(j - x));
      ll len = min(abs(j - i), stock);
      m[len]++;
    }
  }
  for (ll i = 1; i < n; i++) {
    cout << m[i] << endl;
  }
}