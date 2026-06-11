#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)
#define all(a) a.begin(), a.end()

const ll INF = (ll)(1e18)+1;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  string s;
  cin >> s;
  reverse(all(s));
  int p = 0, ans = 0;
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    int d = s[i] - '0' + p;
    if (d > 5) {
      ans += (10 - d);
      p = 1;
    } else if (d < 5) {
      ans += d;
      p = 0;
    } else {
      ans += 5;
      p = 0;
      if (i != n-1 && s[i+1]-'0' >= 5) p = 1;
    }
  }
  ans += p;
  cout << ans << endl;
}