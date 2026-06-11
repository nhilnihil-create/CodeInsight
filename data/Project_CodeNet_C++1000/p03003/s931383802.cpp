#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i=0; i<n; ++i)
typedef long long ll;

const int mod = 1e9 + 7;
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

int main(void){
  int n, m;
  cin >> n >> m;
  vector<int> s(n+1), t(m+1);
  rep(i, n) scanf("%d", &s[i]);
  rep(j, m) scanf("%d", &t[j]);
  
  dp0[0][0] = 1;
  rep(i, n+1) rep(j, m+1) {
    dp0[i+1][j] += dp0[i][j];
    dp1[i][j] += dp0[i][j];
    dp1[i][j+1] += dp1[i][j];
    if (s[i] == t[j]) {
      dp0[i+1][j+1] += dp1[i][j];
    }
  }
  mint ans = dp1[n][m];
  cout << ans.x << endl;
  return 0;
}
