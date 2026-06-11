#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int main() {
  ll s;
  cin >> s;
  ll x1, x2, x3, y1, y2, y3;
  ll v = 1000000000;
  x1 = 0;
  y1 = 0;
  x2 = v;
  y2 = 1;
  x3 = 0;
  y3 = 0;
  // 10^9 * y3 - x3 = S
  x3 = (v - (s % v)) % v;
  y3 = (s + x3) / v;

  cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3
       << " " << endl;
}