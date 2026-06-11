#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr int INF = 2e9;
constexpr int mod = 1e9+7;

int main() {
  int n, m;
  cin >> n >> m;
  vector<P> key;
  rep(i,m) {
    int a, b;
    cin >> a >> b;
    int cur = 0;
    rep(j,b) {
      int c;
      cin >> c; c--;
      cur |= (1 << c);
    }
    key.emplace_back(make_pair(a, cur));
  }

  vector<int> dp(1 << n, INF);
  dp[0] = 0;

  for (int bit = 0; bit < (1 << n); bit++) {
    for (int i = 0; i < m; i++) {
      dp[bit | key[i].second] = min(dp[bit | key[i].second], dp[bit] + key[i].first);
    }
  }
  cout << (dp[(1 << n) - 1] == INF ? -1 : dp[(1 << n) - 1]) << endl;
  return 0;
} 
