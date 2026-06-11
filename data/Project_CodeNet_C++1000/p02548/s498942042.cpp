#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define repr(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
using ll = long long;
using Graph = vector<vector<int>>;
// using P = pair<ll, ll>;
const int dx[] = {0, 1, -1, 0};
const int dy[] = {1, 0, 0, -1};
const ll mod = 1e9 + 7;
const ll INF = 1e9;
const ll LINF = 1LL << 60;

int binarySearch(int key, vector<int> a, int n) {
  vector<int>::iterator it = lower_bound(ALL(a), key);
  if (*it == key) return 1;
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////
  ll n, ans = 0;
  cin >> n;
  n--;
  for (int i = 1; i <= n; ++i) {
    ans += n / i;
  }
  cout << ans << endl;
  return 0;
}
