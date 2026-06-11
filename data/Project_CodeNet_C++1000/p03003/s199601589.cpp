#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
const int INF = 1e9;

struct mint {
  ll x;
  mint(ll x=0):x(x%mod){}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
};
 
mint dp0[2005][2005];
mint dp1[2005][2005];
 
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> s(n+1), t(m+1);
  for(int i = 0; i < n; i++) cin >> s[i];
  for(int i = 0; i < m; i++) cin >> t[i];
  dp0[0][0] = 1;
  for(int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      // printf("%d %d : %lld %lld\n", i,j,dp0[i][j].x,dp1[i][j].x);
      dp0[i+1][j] += dp0[i][j];
      dp1[i][j] += dp0[i][j];
      dp1[i][j+1] += dp1[i][j];
      if (s[i] == t[j]) {
        dp0[i+1][j+1] += dp1[i][j];
      }
    }
  }
  mint ans = dp1[n][m];
  cout << ans.x << endl;
  return 0;
}