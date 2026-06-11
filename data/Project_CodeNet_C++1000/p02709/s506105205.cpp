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
  ll n;
  cin >> n;
  vector<pll> a(n);
  for(ll i=0;i<n;i++) {
    ll tmp;
    cin >> tmp;
    a[i]={tmp,i};
  }
  sort(a.rbegin(),a.rend());
  mat dp(n+1,vec(n+1));
  for(ll i=1;i<=n;i++) {
    ll id=a[i-1].second;
    ll v=a[i-1].first;
    for(ll j=0;j<i;j++) {
      dp[i][j]=max(dp[i][j],dp[i-1][j]+abs((n-1-(i-1-j))-id)*v);
      dp[i][j+1]=max(dp[i][j+1],dp[i-1][j]+abs(j-id)*v);
    }
  }
  ll ans=0;
  for(ll i=0;i<=n;i++) {
    ans=max(ans,dp[n][i]);
  }
  cout << ans << endl;
}