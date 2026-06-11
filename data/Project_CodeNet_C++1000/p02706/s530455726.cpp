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
  int n, m;
  cin >> n >> m;
  REP(i, m) {
    int a;
    cin >> a;
    n -= a;
    if (n < 0) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << n << endl;

  return 0;
}