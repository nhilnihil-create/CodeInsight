#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

int main() {
  int n, m;
  cin >> n >> m;
  // even + even = even ---> ok
  // odd + odd = even ---> ok
  // odd + even = odd ---> ng
  int ans = n * (n - 1) / 2 + m * (m - 1) / 2;
  cout << ans << endl;
}
