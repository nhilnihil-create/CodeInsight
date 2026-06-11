#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long int li;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef pair<ll, ll>P;
#define PI 3.14159265358979
#define MOD 998244353
const int MAX = 510000;

int main() {
  int N,W;
  cin>>N>>W;
  char s[N][W];
  int dp[N][W];
  int dx[2]={0,1};
  int dy[2]={1,0};
  rep(i,N){
  	rep(j,W){
      cin>>s[i][j];
      dp[i][j]=1000;
    }
  }
  
  dp[0][0]=0;
  if(s[0][0]=='#')dp[0][0]=1;
  for(int i=0;i<N;i++){
  	for(int j=0;j<W;j++){
    	for(int d=0;d<=1;d++){
          int ni=i+dx[d],nj=j+dy[d];
          if(ni>=N||nj>=W){continue;}
          if(s[i][j]=='.'&&s[ni][nj]=='#'){dp[ni][nj]=min(dp[i][j]+1,dp[ni][nj]);}
          else{dp[ni][nj]=min(dp[ni][nj],dp[i][j]);}
        }
    }
  }
  cout<<dp[N-1][W-1];
}