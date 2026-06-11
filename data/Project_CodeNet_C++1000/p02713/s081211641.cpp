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
  int k;
  cin >> k;
  int ans = 0;
  for (int a = 1; a < k + 1; a++) {
    for (int b = 1; b < k + 1; b++) {
      for (int c = 1; c < k + 1; c++) {
        ans += __gcd(__gcd(a, b), c);
      }
    }
  }

  cout << ans << endl;
  return 0;
}