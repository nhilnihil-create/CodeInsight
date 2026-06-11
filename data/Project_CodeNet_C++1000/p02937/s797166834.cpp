#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;
const int INF = 1001001001;
const ll MAXV = 1e18;

int main() {
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();
  vector<vector<int>> ch(26);
  rep(i, n) ch[s[i] - 'a'].push_back(i);
  rep(i, n) ch[s[i] - 'a'].push_back(i + n);

  ll ans = 0;
  int pos = 0;
  rep(i, m) {
    int c = t[i] - 'a';
    auto it = lower_bound(ch[c].begin(), ch[c].end(), pos);
    if (it == ch[c].end()) {
      cout << -1 << endl;
      return 0;
    }
    pos = *it + 1;
    if (pos >= n) {
      pos -= n;
      ans += n;
    }
  }

  ans += pos;
  cout << ans << endl;
}