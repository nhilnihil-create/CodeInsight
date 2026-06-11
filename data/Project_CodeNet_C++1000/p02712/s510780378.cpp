#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); i++)

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);

int main() {
  ll n;
  cin >> n;
  vector<ll> a;
  for (ll i = 1; i < n + 1; i++) {
    if (i % 5 == 0) continue;
    if (i % 3 == 0) continue;
    a.push_back(i);
  }
  ll cnt = 0;
  REP(i, a.size()) { cnt += a[i]; }
  cout << cnt << endl;
  return 0;
}