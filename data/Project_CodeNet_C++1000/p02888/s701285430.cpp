#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  int n;
  cin >> n;
  vector<int> l(n);
  rep(i,n) cin >> l[i];
  sort(l.begin(), l.end());
  ll ans = 0;
  rep(i,n-2) {
    for (int j = i+1; j < n-1; j++)
    {
      int k = l[i] + l[j];
      auto iter = lower_bound(l.begin(), l.end(), k) - l.begin();
      if (iter > j) ans += (iter-j-1);
    }
  }
  cout << ans << endl;
  return 0;
}