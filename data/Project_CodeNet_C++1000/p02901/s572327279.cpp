#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;
struct KEY{
  int price;
  int box;
};

int main() {
  int N,M;
  cin>>N>>M;
  vector<KEY> v(M);
  for(int i = 0; i < M; i++){
    int a,b;
    cin>>a>>b;
    v[i].price = a;
    v[i].box=0;
    for(int j = 0; j < b; j++) {
      int t;
      cin>>t;
      t--;
      v[i].box+=(1<<t);
    }
  }
  vector<vector<int>> dp(M+1,vector<int>((1<<N),-1));
  dp[0][0]=0;
  for(int i = 0; i < M; i++){
    dp[i+1][0]=0;
    for(int j = 0; j < (1<<N);j++){
      if(dp[i][j]==-1) continue;
      if(dp[i+1][j]==-1)dp[i+1][j]=dp[i][j];
      else chmin(dp[i+1][j],dp[i][j]);
      int nj = (j|v[i].box);
      if(dp[i+1][nj]==-1) dp[i+1][nj]=dp[i][j]+v[i].price;
      else chmin(dp[i+1][nj],dp[i][j]+v[i].price);
    }
  }
  cout<<dp[M][(1<<N)-1]<<endl;
}