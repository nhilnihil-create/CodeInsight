#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const int inf=1<<30;

ll dp[1000010][2];

int main(){
  string s; cin >> s;
  reverse(all(s));
  int n=s.size();
  rep(i,n+1)rep(j,2) dp[i][j]=inf;
  dp[0][0]=0;
  rep(i,n){
    int nd=s[i]-'0';
    chmin(dp[i+1][1],10-nd+dp[i][0]);
    chmin(dp[i+1][1],10-nd-1+dp[i][1]);
    chmin(dp[i+1][0],nd+dp[i][0]);
    chmin(dp[i+1][0],nd+1+dp[i][1]);
    dp[i+1][1]%=mod;
    dp[i+1][0]%=mod;
  }
  ll ans=min(dp[n][1]+1,dp[n][0]);
  cout << ans << endl;
}