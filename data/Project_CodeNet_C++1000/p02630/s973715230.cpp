/*input
2
1 2
3
1 100
2 100
100 1000
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> cnt(1e5+5);
  ll ans = 0;
  rep(i, n) {
    int a;
    cin >> a;
    cnt[a]++;
    ans += a;
  }

  int q;
  cin >> q;
  rep(i, q) {
    int b, c;
    cin >> b >> c;
    ans += (ll)cnt[b]*(c-b);
    cout << ans << endl;
    cnt[c] += cnt[b];
    cnt[b] = 0;
  }
}