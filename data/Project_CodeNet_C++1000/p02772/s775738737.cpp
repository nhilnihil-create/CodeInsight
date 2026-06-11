#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (ll i = 0; i < n; i++)
#define INF 9223372036854775807
#define all(x) (x).begin(), (x).end()

ll ts = 1000000007;

int main() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  REP(i, n) { cin >> a[i]; };

  bool can = true;
  REP(i, n) {
    if (a[i] % 2 == 0 && a[i] % 3 != 0 && a[i] % 5 != 0) {
      can = false;
    }
  }
  cout << (can ? "APPROVED" : "DENIED") << "\n";
}