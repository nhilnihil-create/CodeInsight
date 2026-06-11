#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a; i < (int)(b); i++)
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP1(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  REP(i, n) { cin >> a[i]; }
  a.push_back(0);
  ll mon = 1000;
  ll cab = 0;
  REP(i, n) {
    cab += mon / a[i];
    mon %= a[i];
    if (a[i] < a[i + 1]) {
      continue;
    } else {
      mon += cab * a[i];
      cab = 0;
    }
  }
  cout << mon << endl;
  return 0;
}
