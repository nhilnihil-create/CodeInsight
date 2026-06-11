#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const int INF = 1000000005;

const ll maxp = 100000 * 10000 + 1;

int n, k, w[100005];

bool check(int p) {
  int i = 0;
  rep(j, k) {
    int t = p;
    while (t >= w[i]) {
      t -= w[i];
      i++;
      if (i == n) return true;
    }
  }
  return false;
}

ll binarySearch(ll left, ll right) {
  if (left >= right) return left;
  ll mid = (left + right) / 2;
  if (check(mid)) binarySearch(left, mid);
  else binarySearch(mid + 1, right);
}

int main() {
  cin >> n >> k;
  rep(i, n) cin >> w[i];

  cout << binarySearch(0, maxp) << endl;;

  
  return 0;
}
