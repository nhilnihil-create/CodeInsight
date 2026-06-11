#include<algorithm>
#include<iostream>
#include<utility>
#include<string>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,x,n) for(int i=x;i<n;i++)
#define int long long
using namespace std;
const int INF=1000000007;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int dp[200][20000];
signed main(){
  int N,W;
  cin>>N>>W;
  vector<int> v(N),w(N);  
  rep(i,200)rep(j,20000)dp[i][j]=-1;
  rep(i,N){
    cin>>v[i]>>w[i];
  }
  dp[0][0]=0;
  rep(i,N)rep(j,W+1){
    if(dp[i][j]==-1)continue;
    dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
    dp[i+1][j+w[i]]=max(dp[i+1][j+w[i]],dp[i][j]+v[i]);
  }
  int ans=0;
  rep(i,W+1){
    if(ans<dp[N][i]){
      ans=dp[N][i];
    }
  }
  cout<<ans<<endl;
    
    return 0;
}