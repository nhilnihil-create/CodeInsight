#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define SIZE(x) ((int)(x).size())

typedef map<int, int> M;
typedef pair<int, int> P;
typedef long long ll;

int main() {
  ll n, m = 1000;
  cin >> n;
  vector<ll> a(n);
  REP(i, n) {
    cin >> a[i];
  }
  REP(i, n-1) {
    ll tmp = 0;
    if (a[i] < a[i+1]) {
      tmp = m / a[i];
    }
    m += (a[i+1] - a[i]) * tmp;
  }
  cout << m << endl;
  return 0;
}
