/*input
6 727202214173249351
6 5 2 5 3 2
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<int> to(n);
  rep(i, n) cin >> to[i], --to[i];
  vector<int> t;
  vector<int> lv(n, -1);
  int len = 0;
  int p = 0;
  while (lv[p] == -1) {
    t.push_back(p);
    lv[p] = len;
    len++;
    p = to[p];
  }
  int ans = 0;
  if (k < len) ans = t[k];
  else {
    k -= len;
    k %= (len-lv[p]);
    ans = t[lv[p]+k];
  }
  cout << ans+1 << endl;
  return 0;
}