#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;

#define FOR(i, a, n) for (int i = (int)a; i < (int)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
#define MOD 1000000007
#define INF 1000000000
#define PI 3.14159265359
#define EPS 1e-12

int main(void) {
  while (true) {
    int n, m;
    vector<PII> a;
    cin >> n >> m;
    if (!n && !m)
      break;
    REP(i, n) {
      int d, p;
      cin >> d >> p;
      a.push_back(make_pair(p, d));
    }
    sort(ALL(a), greater<PII>());

    int cost = 0;
    REP(i, n) {
      if (a[i].second <= m)
        m -= a[i].second;
      else if (m > 0) {
        cost += a[i].first * (a[i].second - m);
        m = 0;
      } else {
        cost += a[i].first * a[i].second;
      }
    }

    cout << cost << endl;
  }
  return 0;
}