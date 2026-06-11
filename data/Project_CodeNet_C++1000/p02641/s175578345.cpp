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
  int x, n;
  cin >> x >> n;
  vector<int> p(n);
  rep(i, n) cin >> p[i];
  sort(p.begin(), p.end());
  if (!binary_search(p.begin(), p.end(), x)) {
    cout << x << endl;
    return 0;
  }
  rep(i, p[n - 1] + 1) {
    if (!binary_search(p.begin(), p.end(), x - i)) {
      cout << x - i << endl;
      return 0;
    }
    if (!binary_search(p.begin(), p.end(), x + i)) {
      cout << x + i << endl;
      return 0;
    }
  }

  return 0;
}