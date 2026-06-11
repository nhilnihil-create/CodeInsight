#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair <int, int>;
const double PI = acos(-1);
const ll MOD = 1000000007;

int main() {
  string s, t;
  cin >> s >> t;
  int n = sz(s), m = sz(t);

  vector<vector<int>> dp(26, vector<int>(0));
  rep(i, n) dp[s[i]-'a'].push_back(i);
  rep(i, n) dp[s[i]-'a'].push_back(i+n);

  ll ans = 0;
  int pre_t = 0;
  bool h = 1;

  rep(i, m){
    int t_now = t[i] - 'a';
    if (dp[t_now].size() == 0){
      h = 0;
      break;
    }
    auto it = lower_bound(dp[t_now].begin(),dp[t_now].end(), pre_t);
    int index = it - dp[t_now].begin();
    int t_next = dp[t_now][index];
    ans += t_next - pre_t +1;
    pre_t = t_next % n +1;
  }

  if(h) cout << ans << endl;
  else cout << -1 << endl;

}
