#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
const ll M = 1e9 + 7;

int main(void){
  int n, m; ll B;
  scanf("%d %d", &n, &m);

  vl ks(m, 0), ps(m); B = 1LL << n;
  vector<vl> dp(B, vl(m + 1, M));

  rep(i, m){
    int b;
    scanf("%lld %d", &ps[i], &b);
    rep(j, b){
      int c;
      scanf("%d", &c); c--;
      ks[i] |= 1LL << c;
    }
  }

  dp[0][0] = 0;
  rep(i, m){
    rep(bit, B){
      dp[bit][i + 1] = dp[bit][i];
      ll res = bit & ~ks[i];
      dp[bit][i + 1] = min(dp[bit][i + 1], dp[res][i] + ps[i]);
    }
  }

  ll ans = dp[B - 1][m];
  if (ans != M) cout << ans << endl;
  else cout << -1 << endl;

  return 0;
}
