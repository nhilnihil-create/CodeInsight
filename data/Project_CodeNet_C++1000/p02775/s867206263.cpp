#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
struct edge { ll s, t, x; };
typedef pair<ll, ll> P;
typedef pair<ll,P> event;
const ll MAX = 510000;
const ll MOD = 1000000007;

int main() {
  string S;
  cin>>S;
  ll n=(ll)S.size();
  int dp[n+1ll][2];
  rep(i,n+1ll){dp[i][0]=0ll;dp[i][1]=0ll;}
  dp[0][1]=1ll;dp[0][0]=0ll;
  rep(i,n){
    dp[i+1][0]=min(dp[i][0]+(S[i]-'0'),dp[i][1]+10-(S[i]-'0'));
    if(S[i]!='9'){dp[i+1][1]=min(dp[i][0]+1+(S[i]-'0'),dp[i][1]+9-(S[i]-'0'));}
    else{dp[i+1][1]=dp[i][1]+9-(S[i]-'0');}
  }
  
  cout<<min(dp[n][0],dp[n][1]+1)<<endl;
}
