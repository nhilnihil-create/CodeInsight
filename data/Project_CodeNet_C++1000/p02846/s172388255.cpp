#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) (v).begin(), (v).end()
#define coutd(n) cout << fixed << setprecision(n)
#define ll long long int
#define vl vector<ll>
#define vi vector<int>
const int INF = 2147483647;
const ll MOD = 1000000007;

using namespace std;

int main() {
  ll t1, t2;
  ll a1, a2;
  ll b1, b2;
  cin >> t1 >> t2;
  cin >> a1 >> a2;
  cin >> b1 >> b2;

  a1 = t1 * a1;
  b1 = t1 * b1;
  a2 = t2 * a2;
  b2 = t2 * b2;
  if (a1 + a2 == b1 + b2) {
    cout << "infinity" << endl;
    return 0;
  }
  if (a1 <= b1) {
    ll tmp = a1;
    a1 = b1;
    b1 = tmp;
    tmp = a2;
    a2 = b2;
    b2 = tmp;
  }
  ll k = 1LL;

  ll d = b1 + b2 - a1 - a2;
  if (d < 0) {
    cout << 0 << endl;
    return 0;
  }

  k = floor((double)(a1 - b1) / d);
  k *= 2;
  if ((b1 - a1) % d != 0) {
    k++;
  }

  cout << k << endl;
}
