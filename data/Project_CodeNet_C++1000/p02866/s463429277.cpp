#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<deque>
#include<queue>
#include<numeric>
using namespace std;

using ll = long long;
const int INF = 1001001001;
const ll LLINF = 1001001001001001001;
const int MOD = 1000000007;

#define rep(i,n) for (int i = 0; i < (n); ++i)

int main()
{
  int n;
  cin >> n;
  vector<int> d(n);
  rep (i, n) cin >> d[i];
  if (d[0] != 0) {
    cout << 0 << endl;
    return 0;
  }
  sort(d.begin(), d.end());

  vector<int> a(n+5, 0);
  int now = 0;
  rep (i, n) {
    if (d[i] == now) {
      a[now]++;
    } else {
      if (now+1 == d[i]) {
        now++;
        a[now]++;
      } else {
        cout << 0 << endl;
        return 0;
      }
    }
  }

  if (a[0] != 1) {
    cout << 0 << endl;
    return 0;
  }

  int idx = 2;
  int pre = a[1] % 998244353;
  ll res = 1;
  while (a[idx] > 0) {
    rep (i, a[idx]) {
      res *= pre % 998244353;
      res %= 998244353;
    }
    pre = a[idx];
    idx++;
  }

  cout << res << endl;
}
