/*
 *  WATCH THIS
 */
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll N = 1e5 + 5, OO = 0x3f3f3f3f, mod = 1e9 + 7;

void debug() { cerr << endl; }

template<typename Head, typename... Tail>
void debug(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug(T...);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<ll> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  ll minn = min(v[0], v[1]);
  ll x = (v[0] > v[1] ? 1 : 0);
  ll first = 1000;
  for (int i = x; i < n - 1; ++i) {
    if (v[i + 1] < v[i]) {
      ll buy = first / minn;
      first = first % minn;
      ll sells = v[i] * buy;
      first += sells;
      minn = v[i + 1];
    }
  }
  if (minn != v[n - 1]) {
    ll buy = first / minn;
    first = first % minn;
    ll sells = v[n - 1] * buy;
    first += sells;
  }
  cout << max((ll) 1000, first) << endl;
  return 0;
}