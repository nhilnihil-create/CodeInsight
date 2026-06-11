#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef pair<int, int> P;

const long double EPS = 1e-10;
const long long INF = 1e18;
const int MOD = (int)1e9 + 7;
const long double PI = acos(-1.0L);

int main() {  // TODO
  int n;
  cin >> n;
  vector<int> a(n + 1);
  rep(i, n) cin >> a[i + 1];
  int ans = 0;
  int e = 1;
  int i = 1;
  while (i <= n) {
    if (a[i] == e) {
      i++;
      e++;
    } else {
      i++;
      ans++;
    }
  }
  if (e == 1) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }

  return 0;
}