#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

int main() {
  ll n,m;
  cin >> n >> m;
  vec s(n),t(m);
  for(ll i=0;i<n;i++) cin >> s[i];
  for(ll i=0;i<m;i++) cin >> t[i];
  mat sum(n+1,vec(m+1,0));
  mat dp(n+1,vec(m+1,0));
  for(ll i=0;i<n;i++) {
    for(ll j=0;j<m;j++) {
      if(s[i]==t[j]) {
        dp[i+1][j+1]=(sum[i][j]+1)%mod;
      }
      sum[i+1][j+1]=(sum[i+1][j]+sum[i][j+1]-sum[i][j]+dp[i+1][j+1]+mod)%mod;
    }
  }
  cout << (sum[n][m]+1)%mod << endl;
}