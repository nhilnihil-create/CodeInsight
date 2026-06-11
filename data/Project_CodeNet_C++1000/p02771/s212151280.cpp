#include <bits/stdc++.h>
#define FOR(i, m, n) for (int i = m; i < (n); i++)
#define RFOR(i, m, n) for (int i = (m - 1); i >= 0; i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, n, 0)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define print(ele) cout << ele << endl
#define print10(ele) cout << fixed << setprecision(10) << ele << endl

using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const ll INF = 1000000000000000000LL;


int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a != b && a == c) {
    puts("Yes");
  } else if (a == b && a != c) {
    puts("Yes");
  } else if (a != b && b == c) {
    puts("Yes");
  } else {
    puts("No");
  }
  return 0;
}
