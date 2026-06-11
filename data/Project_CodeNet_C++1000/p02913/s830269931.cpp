#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define cvector vector<char>
#define svector vector<string>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define rep(i,n) for(ll i=0; i<n; ++i)
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,ans=0,x;string s;cin>>n>>s;
  vector<lvector> dp(5001,lvector(5001,0));
  for(ll i=n-1;i>-1;--i) {
    for(ll j=n-1;j>-1;--j) {
      if(s[i]!=s[j]) continue;
      else dp[i][j]=dp[i+1][j+1]+1;
    }
  }
  rep(i,n)rep(j,n) {
    if(i>=j) continue;
    x=min(dp[i][j],j-i);
    ans=max(ans,x);
  }
  print(ans);
  return 0;
}