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
  vec a(n),b(m);
  for(ll i=0;i<n;i++) cin >> a[i];
  for(ll i=0;i<m;i++) cin >> b[i];
  mat dp(n+1,vec(m+1)),ans(n+1,vec(m+1));
  for(ll i=0;i<n;i++) {
    map<ll,ll> cnt;
    for(ll j=0;j<m;j++) {
      ans[i+1][j+1]=(ans[i+1][j]+ans[i][j+1]-ans[i][j]+mod)%mod;
      if(a[i]==b[j]) {
        dp[i+1][j+1]=ans[i][j]+1;
        (ans[i+1][j+1]+=dp[i+1][j+1])%=mod;
      }
    }
  }
  cout << (ans[n][m]+1)%mod << endl;
}