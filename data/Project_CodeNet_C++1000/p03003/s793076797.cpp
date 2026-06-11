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

ll dp[2010][2010];

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> s(n);
  rep(i,n) cin >> s[i];
  vector<int> t(m);
  rep(i,m) cin >> t[i];
  dp[0][0]=1;
  rep(i,n+1)rep(j,m+1){
    if(i-1>=0&&j-1>=0&&s[i-1]==t[j-1]) dp[i][j]+=dp[i-1][j-1];
    dp[i][j]%=mod;
    if(i-1>=0)dp[i][j]+=dp[i-1][j];
    dp[i][j]%=mod;
    if(j-1>=0)dp[i][j]+=dp[i][j-1];
    dp[i][j]%=mod;
    if(i-1>=0&&j-1>=0)dp[i][j]-=dp[i-1][j-1];
    if(dp[i][j]<0) dp[i][j]+=mod;
  }
  cout << dp[n][m] << endl;
}
