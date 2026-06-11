#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define pint pair<int,int>
#define pll pair<ll,ll>
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

ll dp[1000][1000];

int main(){
  int n,K;
  cin >> n >> K;
  ll h[n+1]={};
  rep(i,n)cin >> h[i+1];
  rep(i,500)rep(j,500)dp[i][j]=longinf;
  dp[0][K]=0;
  ll ans=longinf;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=K;j++){
      if(dp[i][j]<longinf){
        for(int k=i+1;k<=min(n,i+j+1);k++){
          dp[k][j-(k-i-1)]=min(dp[k][j-(k-i-1)],dp[i][j]+max(0LL,h[k]-h[i]));
        }
      }
    }
  }
  for(int i=0;i<=n;i++)for(int j=0;j<=K;j++)if(i+j>=n)ans=min(ans,dp[i][n-i]);
  cout << ans << endl;
return 0;}