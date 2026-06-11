#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define repr(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
using ll = long long;
// using Graph = vector<vector<int>>;
const ll mod = 998244353;
const ll INF = 1e9;
const ll LINF = 1LL << 60;

int main() {
  int a[32] = {1, 1, 1, 2, 1, 2, 1, 5,  2, 2, 1, 5, 1, 2, 1, 14,
               1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
  int k;
  cin >> k;
  cout << a[k - 1] << endl;
  return 0;
}
