#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define MAX 305

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

ll INF=1ll<<55;
int n, k;
int H[MAX];
ll dp[MAX][MAX];
/*
dp[x][y]:
*/

int main(){
  cin >> n >> k;
  rep(i,n){
    cin >> H[i+1];
  }
  H[0]=0;
  /*
  memset(dp,INF,sizeof(dp));
  */
  repo(i,n){
    repo(j,n-k){
      dp[i][j]=INF;
    }
  }
  repo(i, n){
    dp[i][0]=0;
    dp[i][1]=H[i];
  }
  for(int j=2; j<=n-k; j++){
    for(int i=j; i<=n; i++){
      repo(l,i-1){
        dp[i][j]=min(dp[l][j-1]+max(0,H[i]-H[l]),dp[i][j]);
      }
    }
  }

  ll ans=INF;
  repo(i,n){
    ans=min(ans,dp[i][n-k]);
  }
  cout << ans << endl;


  return 0;
}
