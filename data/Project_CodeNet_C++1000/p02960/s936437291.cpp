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
  string s;
  cin >> s;
  ll n=s.size();
  mat dp(n+1,vec(13));
  dp[0][0]=1;
  for(ll i=0;i<n;i++) {
    for(ll j=0;j<13;j++) {
      if(s[i]=='?') {
        for(ll k=0;k<10;k++) {
          (dp[i+1][(j*10+k)%13]+=dp[i][j])%=mod;
        }
      }
      else {
        ll id=s[i]-'0';
        (dp[i+1][(j*10+id)%13]+=dp[i][j])%=mod;
      }
    }
  }
  cout << dp[n][5] << endl;
}