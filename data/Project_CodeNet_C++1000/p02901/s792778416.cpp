#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int N = 12, M = 1000;
const int INF = 1e9;

int n, m, a[M], b[M], c[M][N];

int dp[1<<N];

// bitを買うための最小コスト
int rec(int bit) {
  if (dp[bit] != -1) return dp[bit];

  int res = INF;
  rep(i, m) {
    int bi = 0;
    rep(j, b[i]) bi |= 1<<c[i][j];
    if ((bit | bi) == bi) res = min(res, a[i]);
  }

  rep(bi1, 1<<n) {
    if (bi1 == bit) continue;
    if (bi1 == 0) continue;
    if ((bi1 | bit) != bit) continue;
    int bi2 = bit - bi1;
    res = min((ll)res, (ll)rec(bi1) + rec(bi2));
  }
  return dp[bit] = res;
}

int main() {
  cin >> n >> m;
  rep(i, m) {
    cin >> a[i] >> b[i];
    rep(j, b[i]) cin >> c[i][j];
    rep(j, b[i]) c[i][j]--;
  }

  rep(i, 1<<n) dp[i] = -1;
  int ans = rec((1<<n)-1);
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
} 